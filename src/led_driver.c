/** @file	led_driver.c
*
* @brief	Led driver developed under TDD.
*
* @author	Mikhail Chelushkin.
* @version	1.0
* @date		2024/02/09
*/

#include "led_driver.h"

enum
{
	ALL_LEDS_ON = ~0,
	ALL_LEDS_OFF = ~ALL_LEDS_ON
};

// var for record the LED’s state and make less changable leds_address
static uint16_t leds_image;
static uint16_t *leds_address = NULL;

static uint16_t convert_led_number_to_bit(uint8_t led_number);
static void update_hardware(void);

void led_driver_create(uint16_t * const address)
{
	leds_address = address;
	leds_image = ALL_LEDS_OFF;
	update_hardware();
}


void led_driver_destroy(void)
{

}

void led_driver_turn_on(uint8_t led_number)
{
	leds_image |= convert_led_number_to_bit(led_number);
	update_hardware();
}

void led_driver_turn_off(uint8_t led_number)
{
	leds_image &= ~(convert_led_number_to_bit(led_number));
	update_hardware();
}

void led_driver_turn_on_all(void)
{
	leds_image = ALL_LEDS_ON;
	update_hardware();
}

static uint16_t convert_led_number_to_bit(uint8_t led_number)
{
	return 1 << (led_number - 1);
}

static void update_hardware(void)
{
	*leds_address = leds_image;
}

/*** end of file ***/