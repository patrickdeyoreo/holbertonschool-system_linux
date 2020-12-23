#include <pthread.h>
#include <stdio.h>

#include "multithreading.h"

/**
 * thread_entry - write a string to standard output, followed by a newline
 *
 * @arg: pointer to the string print
 *
 * Return: NULL
 */
void *thread_entry(void *arg)
{
	printf("%s\n", (char *) arg);
	pthread_exit(NULL);
}
