#include <errno.h>
#include <error.h>
#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "multithreading.h"

static pthread_mutex_t lock;

static void _pthread_mutex_init(void) __attribute__((constructor));
static void _pthread_mutex_destroy(void) __attribute__((destructor));

/**
 * _pthread_mutex_init - initialize mutex
 */
static void _pthread_mutex_init(void)
{
	if (pthread_mutex_init(&lock, NULL))
		error(EXIT_FAILURE, errno, "mutex initialization failed");
}

/**
 * _pthread_mutex_destroy - destroy mutex
 */
static void _pthread_mutex_destroy(void)
{
	if (pthread_mutex_destroy(&lock))
		error(EXIT_FAILURE, errno, "mutex destruction failed");
}

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
	if (pthread_mutex_lock(&lock))
		error(EXIT_FAILURE, errno, "mutex locking failed");
	n_written += printf("[%lu] ", (unsigned long int) pthread_self());
	n_written += vprintf(format, args);
	if (pthread_mutex_unlock(&lock))
		error(EXIT_FAILURE, errno, "mutex unlocking failed");
	va_end(args);
	return (n_written);
}
