/** @file	runtime_error_stub.h
*
* @brief	************Header for handler of runtime error developed under TDD.
*
* @author	Mikhail Chelushkin.
* @version	1.0
* @date		2024/02/23
*/

#ifndef RUNTIME_ERROR_STUB_H
#define RUNTIME_ERROR_STUB_H

#include "runtime_error.h"

/** @brief Stub reset parameter and message of last error.
*
* @param None
* @return None
*/
void runtime_error_stub_reset(void);

/** @brief Get last error message.
*
* @param None
* @return Message.
*/
const char *runtime_error_stub_get_last_error(void);

/** @brief Get last error parameter.
*
* @param None
* @return Parameter.
*/
int runtime_error_stub_get_last_parameter(void);

#endif // RUNTIME_ERROR_STUB_H