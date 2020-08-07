#ifndef _GETLINE_H_
#define _GETLINE_H_

#include <stdlib.h>
#include <unistd.h>

#define READ_SIZE 4096

/**
 * struct buf_s - input buffer
 * @buffer: the buffer
 * @next: pointer to the next value
 * @remaining: number of values remaining
 */
typedef struct buf_s
{
	char buffer[READ_SIZE];
	char *next;
	size_t remaining;
} buf_t;

char *_getline(const int fd);
ssize_t _strnchr(const char *s, char c, size_t n);
void *_realloc(void *old, size_t old_size, size_t new_size);

#endif /* _GETLINE_H_ */
