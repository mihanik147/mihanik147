/** @file	led_driver_test.cpp
*
* @brief	Led driver developed under TDD.
*
* @author	Mikhail Chelushkin.
* @version	1.0
* @date		2024/02/10
*/

/** @brief
* Список тестов:
1. LED - драйвер управляет 16 - ю светодиодами с двумя состояниями.
2. Драйвер может включать и выключать отдельно любой светодиод  без затрагивания других.
3. Драйвер может включить и выключить все светодиоды с помощью одного вызова из интерфеса.
4. Пользователь драйвера может запросить состояние любого светодиода.
5. По умолчанию при включении питания светодиоды фиксируются.Светодиоды должны отключаться программно.
6. Светодиоды отображаются в памяти в 16 - битное слово(по адресу, который необходимо определить).
7. 1 в позиции бита зажигает соответствующий светодиод; 0 выключает его.
8. Младший бит соответствует светодиоду 1; старший бит соответствует светодиоду 16.
*/

#include "CppUTest/TestHarness.h"
#include <stdint.h>

extern "C"
{
	#include "led_driver.h"
	#include "runtime_error_stub.h"
}

TEST_GROUP(LedDriver)
{
	// If var virtualLeds is defined static, the solution has problems with linking.
	uint16_t virtualLeds;
	void setup()
	{
		led_driver_create(&virtualLeds);
	}

	void teardown()
	{
	}
};

TEST(LedDriver, LedsOffAfterCreate)
{
	uint16_t virtualLeds = 0xffff;
	led_driver_create(&virtualLeds);
	BITS_EQUAL(0, virtualLeds, 0xffff);
}

TEST(LedDriver, TurnOnLedOn)
{
	led_driver_turn_on(1);
	BITS_EQUAL(1, virtualLeds, 0xffff);
}

TEST(LedDriver, TurnOffLedOne)
{
	led_driver_turn_on(1);
	led_driver_turn_off(1);
	BITS_EQUAL(0, virtualLeds, 0xffff);
}

TEST(LedDriver, TurnOnMultipleLeds)
{
	// Turn on led 8 and 9 because they are in two different bytes of uint16_t
	led_driver_turn_on(8);
	led_driver_turn_on(9);
	BITS_EQUAL( ((1<<8-1)+ (1 << 9-1)), virtualLeds, 0xffff);
}

TEST(LedDriver, TurnOnAll)
{
	led_driver_turn_on_all();
	BITS_EQUAL(0xffff, virtualLeds, 0xffff);
}

TEST(LedDriver, TurnOffAnyLed)
{
	led_driver_turn_on_all();
	led_driver_turn_off(8);
	BITS_EQUAL(0xffff - (1 << (8-1)), virtualLeds, 0xffff);
}

TEST(LedDriver, LedMemoryIsNotReadable)
{
	virtualLeds = 0xffff;
	led_driver_turn_on(8);
	BITS_EQUAL(0x80, virtualLeds, 0xffff);
}

TEST(LedDriver, UpperAndLowerBounds)
{
	led_driver_turn_on(1);
	led_driver_turn_on(16);
	BITS_EQUAL(0x8001, virtualLeds, 0xffff);
}

TEST(LedDriver, OutOfBoundsTurnOnDoesNoHarm)
{
	led_driver_turn_on(-1);
	led_driver_turn_on(0);
	led_driver_turn_on(17);
	led_driver_turn_on(3141);
	BITS_EQUAL(0x0000, virtualLeds, 0xffff);
}

TEST(LedDriver, OutOfBoundsTurnOffDoesNoHarm)
{
	led_driver_turn_on_all();

	led_driver_turn_off(-1);
	led_driver_turn_off(0);
	led_driver_turn_off(17);
	led_driver_turn_off(3141);
	BITS_EQUAL(0xffff, virtualLeds, 0xffff);
}

TEST(LedDriver, OutOfBoundsProducesRuntimeError)
{
	led_driver_turn_on(-1);
#if 1
	RUNTIME_ERROR("LED Driver: out-of-bounds LED", -1);
#endif
	STRCMP_EQUAL("LED Driver: out-of-bounds LED", runtime_error_stub_get_last_error());
	LONGS_EQUAL(-1, runtime_error_stub_get_last_parameter());
}

IGNORE_TEST(LedDriver, OutOfBoundsToDo)
{
	/* TODO: what should we do during runtime? */
}