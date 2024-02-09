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

