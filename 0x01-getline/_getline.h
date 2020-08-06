#ifndef _GETLINE_H_
#define _GETLINE_H_

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define READ_SIZE 4096

/**
 * struct buf - a buffer structure
 * @buffer: the buffer
 * @r_pos: the read position
 * @w_pos: the write position
 */
typedef struct buf_s
{
	char buffer[READ_SIZE];
	char *r_pos;
	char *w_pos;
} buf_t;

char *_getline(const int fd);
ssize_t _getline_line(buf_t *buf, ssize_t *len, char **line, size_t *n);
ssize_t _getline_full(buf_t *buf, ssize_t *len, char **line, size_t *n);
ssize_t _strnchr(const char *s, char c, size_t n);
void *_realloc(void *old, size_t old_size, size_t new_size);

#endif /* _GETLINE_H_ */