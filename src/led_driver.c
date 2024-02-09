/** @file	led_driver.c
*
* @brief	Led driver developed under TDD.
*
* @author	Mikhail Chelushkin.
* @version	1.0
* @date		2024/02/09
*/

#include "led_driver.h"

static uint16_t *leds_address = NULL;

void led_driver_create(uint16_t * const address)
{
	leds_address = address;
	*leds_address = 0x0000;
}


void led_driver_destroy(void)
{

}

void led_driver_turn_on(uint8_t ledNumber)
{
	*leds_address = 1;
}

void led_driver_turn_off(uint8_t ledNumber)
{
	*leds_address = 0;
}

/*** end of file ***/