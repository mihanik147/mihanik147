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

enum
{
	FIRST_LED = 1,
	LAST_LED = 16 
};

// var for record the LED’s state and make less changable leds_address
static uint16_t leds_image;
static uint16_t *leds_address = NULL;

static uint16_t convert_led_number_to_bit(uint8_t led_number);
static void update_hardware(void);
static bool is_led_out_of_bounds(int led_number);
static void set_led_image_bit(int led_number);
static void clear_led_image_bit(int led_number);

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
	if (is_led_out_of_bounds(led_number))
	{
		return;
	}

	set_led_image_bit(led_number);
	update_hardware();
}

void led_driver_turn_off(uint8_t led_number)
{
	if (is_led_out_of_bounds(led_number))
	{
		return;
	}

	clear_led_image_bit(led_number);
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

static bool is_led_out_of_bounds(int led_number)
{
	return (led_number < FIRST_LED) || (led_number > LAST_LED);
}

static void set_led_image_bit(int led_number)
{
	leds_image |= convert_led_number_to_bit(led_number);
}

static void clear_led_image_bit(int led_number)
{
	leds_image &= ~convert_led_number_to_bit(led_number);
}

/*** end of file ***/