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

static uint16_t convert_led_number_to_bit(uint8_t led_number);

void led_driver_create(uint16_t * const address)
{
	leds_address = address;
	*leds_address = 0x0000;
}


void led_driver_destroy(void)
{

}

void led_driver_turn_on(uint8_t led_number)
{
	*leds_address |= convert_led_number_to_bit(led_number);
}

void led_driver_turn_off(uint8_t led_number)
{
	*leds_address = 0;
}


static uint16_t convert_led_number_to_bit(uint8_t led_number)
{
	return 1 << (led_number - 1);
}

/*** end of file ***/