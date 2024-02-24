/** @file	runtime_error.h
*
* @brief	Header for handler of runtime error developed under TDD.
*
* @author	Mikhail Chelushkin.
* @version	1.0
* @date		2024/02/23
*/

#ifndef RUNTIME_ERROR_H
#define RUNTIME_ERROR_H

void RuntimeError(const char *message, int parameter,
	const char	*file, int line);

#define RUNTIME_ERROR(description, parameter)\
	RuntimeError(description, parameter, __FILE__, __LINE__)

#endif // RUNTIME_ERROR_H