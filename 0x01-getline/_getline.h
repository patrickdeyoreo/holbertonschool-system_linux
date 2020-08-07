#ifndef _GETLINE_H_
#define _GETLINE_H_

#include <stdlib.h>
#include <unistd.h>

#define TABLE_SIZE 127

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
 * @fd: file descriptor
 * @buf: associated buffer
 * @next: next buffer in chain
 */
typedef struct buf_table_s
{
	int fd;
	struct buf_s buf;
	struct buf_table_s *next;
} buf_table_t;

char *_getline(const int fd);

#endif /* _GETLINE_H_ */
