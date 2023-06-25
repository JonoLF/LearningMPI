/**
 * @file epccutil.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-18
 * 
 * @copyright Copyright (c) 2023
 * 
 **/
#include <epccutil.h>
#include <string.h>
#include <stdarg.h>

void EPCC_printf(const char* format, ...)
{
    const int BUFFER_SIZE = 2048;
	char buffer[BUFFER_SIZE];
	snprintf(buffer, BUFFER_SIZE, "[Thread %d] ", omp_get_thread_num());

	int buffer_size_remaining = BUFFER_SIZE - strlen(buffer);
	va_list arguments;
	va_start(arguments, format);
	vsnprintf(buffer + strlen(buffer), buffer_size_remaining, format, arguments);
	va_end(arguments);

	printf("%s", buffer);
}