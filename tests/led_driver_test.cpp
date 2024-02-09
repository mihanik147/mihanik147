#include "CppUTest/TestHarness.h"
#include <stdint.h>

extern "C"
{
#	include "led_driver.h"
}

TEST_GROUP(LedDriver)
{
	void setup()
	{
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
	uint16_t virtualLeds;
	led_driver_create(&virtualLeds);
	led_driver_turn_on(1);
	BITS_EQUAL(1, virtualLeds, 0xffff);
}

TEST(LedDriver, TurnOffLedOne)
{
	uint16_t virtualLeds;
	led_driver_create(&virtualLeds);
	led_driver_turn_on(1);
	led_driver_turn_off(1);
	BITS_EQUAL(0, virtualLeds, 0xffff);
}