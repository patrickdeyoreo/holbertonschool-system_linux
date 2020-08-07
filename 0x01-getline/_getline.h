#ifndef _GETLINE_H_
#define _GETLINE_H_

#include <stdlib.h>
#include <unistd.h>

#define FD_MAX 255

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

/**
 * struct buf_table_s - input buffer hash table
 * @next: next buffer in chain
 * @fd: file descriptor
 * @buf: associated buffer
 */
typedef struct buf_table_s
{
	struct buf_table_s *next;
	int fd;
	struct buf_s *buf;
} buf_table_t;

char *_getline(const int fd);

#endif /* _GETLINE_H_ */
