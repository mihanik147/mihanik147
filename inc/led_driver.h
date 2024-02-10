/** @file	led_driver.h
*
* @brief	Led driver developed under TDD.
* 
* @author	Mikhail Chelushkin.
* @version	1.0
* @date		2024/02/09
*/

#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <stdint.h>

/** @brief Create object of led driver and off all leds.
*
* @param[in,out] address The memory address of leds.s
* @return None
*/
void led_driver_create(uint16_t * const address);

/** @brief Destroy object of led driver.
*
* @param None
* @return None
*/
void led_driver_destroy(void);

/** @brief Turn on the led with ledNumber.
*
* @param[in] ledNumber The number of led turned on.
* @return None
*/
void led_driver_turn_on(uint8_t ledNumber);

/** @brief Turn off the led with ledNumber.
*
* @param[in] ledNumber The number of led turned off.
* @return None
*/
void led_driver_turn_off(uint8_t ledNumber);

/** @brief Turn on all leds.
*
* @param None
* @return None
*/
void led_driver_turn_on_all(void);

#endif // LED_DRIVER_H

/*** end of file ***/
