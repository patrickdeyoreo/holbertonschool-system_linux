#include <string.h>

#include "_getline.h"

/**
 * _memchr - get the index of the first matching value
 * @s: array to search
 * @c: value to find
 * @n: number of elements to check
 * Return: If c does not occur in the first n elements of s, return -1.
 * Otherwise, return the index of the first occurence of c.
 */
static ssize_t _memchr(const char *s, char c, size_t n)
{
	ssize_t i = 0;

	if (s)
	{
		while (n--)
		{
			if (s[i] == c)
				return (i);
			i += 1;
		}
	}
	return (-1);
}

/**
 * _realloc - reallocate a buffer
 * @old: pointer to the buffer
 * @old_size: current size of the buffer
 * @new_size: desired size of the buffer
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the new buffer.
 */
static void *_realloc(void *old, size_t old_size, size_t new_size)
{
	void *new = NULL;

	if (old)
	{
		if (new_size)
		{
			new = malloc(new_size);
			if (new)
			{
				memcpy(new, old, old_size < new_size ? old_size : new_size);
				free(old);
			}
		}
		else
		{
			free(old);
		}
	}
	return (new);
}

/**
 * _getline_next - read a line of input
 * @buf: pointer to the static buffer
 * @line: address of a pointer to the line
 * @size: address of a pointer to the line size
 * @n: number of characters to copy from the buffer
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the line of input.
 */
static char *_getline_next(buf_t *buf, char **line, size_t *size, size_t n)
{
	char *temp = NULL;

	if (*line)
		temp = _realloc(*line, *size, *size + n);
	else
		temp = malloc(n + 1);

	if (temp)
	{
		*line = temp;

		if (*size)
			*size -= 1;

		memcpy(*line + *size, buf->next, n);
		*size += n;

		(*line)[*size] = '\0';
		*size += 1;
	}
	else
	{
		free(*line);
		*line = NULL;
		*size = 0;
	}
	return (*line);
}

/**
 * _getline - read a line of input
 * @fd: file descriptor from which to read
 * Return: If an error occurs or there are no more lines, return NULL.
 * Otherwise, return the next line of input.
 */
char *_getline(const int fd)
{
	static buf_t buf;
	char *line = NULL;
	size_t size = 0;
	ssize_t eol = 0, n_read = 0;

	if (fd > -1)
	{
		do {
			if (buf.remaining == 0)
				buf.next = buf.buffer;
			if (n_read)
				buf.remaining = n_read;
			if (buf.remaining)
			{
				eol = _memchr(buf.next, '\n', buf.remaining);
				if (eol == -1)
				{
					if (_getline_next(&buf, &line, &size, buf.remaining))
						buf.next += buf.remaining, buf.remaining = 0;
					else
						break;
				}
				else
				{
					if (_getline_next(&buf, &line, &size, eol))
						buf.next += eol + 1, buf.remaining -= eol + 1;
					break;
				}
			}
		} while ((n_read = read(fd, buf.buffer, READ_SIZE)) > 0);
		if (n_read == -1)
		{
			free(line);
			line = NULL;
			size = 0;
		}
	}
	return (line);
}
