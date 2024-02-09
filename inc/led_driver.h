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
void led_driver_create(uint16_t * address);

/** @brief Destroy object of led driver.
*
* @param None
* @return None
*/
void led_driver_destroy(void);

#endif // LED_DRIVER_H

/*** end of file ***/
