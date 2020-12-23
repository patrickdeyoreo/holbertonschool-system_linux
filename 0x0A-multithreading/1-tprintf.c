#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>

#include "multithreading.h"

/**
 * tprintf - format and write a given string to standard output
 *
 * @format: pointer to the format string
 * @...: format string argument list
 *
 * Return: number of characters written
 */
int tprintf(char const *format, ...)
{
	va_list args;
	int n_written = 0;

	va_start(args, format);
	n_written += printf("[%lu] ", (unsigned long int) pthread_self());
	n_written += vprintf(format, args);
	va_end(args);
	return (n_written);
}
