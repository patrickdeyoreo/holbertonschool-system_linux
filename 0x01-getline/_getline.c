#include <string.h>

#include "_getline.h"

/**
 * _strnchr - get the index of the first matching character
 * @s: string passed
 * @c: character passed
 * @n: max number of characters to check
 * Return: Index of the first occurence, or -1 c is not found
 */
static ssize_t _strnchr(const char *s, char c, size_t n)
{
	ssize_t i = 0;

	if (n && s)
	{
		while (n && s[i] && s[i] != c)
		{
			i += 1;
			n -= 1;
		}
		if (n && s[i] == c)
			return (i);
	}
	return (-1);
}

/**
 * _realloc - reallocate a buffer
 * @old: pointer to the buffer
 * @old_size: current size of the buffer
 * @new_size: desired size of the buffer
 * Return: NULL if memory allocation fails, otherwise a pointer to the new buffer
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
 * _getline - read a line of input
 * @fd: file descriptor from which to read
 * Return: If an error occurs or there are no more lines, return NULL.
 * Otherwise, return the next line of input.
 */
char *_getline(const int fd)
{
	static buf_t buf = {{0}, NULL, 0};
	char *line = NULL, *temp = NULL;
	size_t size = 0;
	ssize_t eol = 0, n_read = 0;

	if (fd < 0)
		return (NULL);

	do {
		if (n_read == -1)
		{
			free(line);
			line = NULL;
			break;
		}
		if (buf.remaining == 0)
			buf.next = buf.buffer;
		if (n_read)
			buf.remaining = n_read;
		if (buf.remaining)
		{
			eol = _strnchr(buf.next, '\n', buf.remaining);
			if (eol == -1)
			{
				if (line)
					temp = _realloc(line, size, size + buf.remaining);
				else
					temp = malloc(buf.remaining + 1);
				if (!temp)
				{
					free(line);
					line = NULL;
					break;
				}
				line = temp;
				if (size)
					size -= 1;
				memcpy(line + size, buf.next, buf.remaining);
				size += buf.remaining;
				line[size++] = '\0';
				buf.next = buf.buffer;
				buf.remaining = 0;
			}
			else
			{
				if (line)
					temp = _realloc(line, size, size + eol);
				else
					temp = malloc(eol + 1);
				if (!temp)
				{
					free(line);
					line = NULL;
					break;
				}
				line = temp;
				if (size)
					size -= 1;
				memcpy(line + size, buf.next, eol);
				size += eol;
				line[size++] = '\0';
				buf.next += eol + 1;
				buf.remaining -= eol + 1;
				break;
			}
		}
	} while ((n_read = read(fd, buf.buffer, READ_SIZE)));
	return (line);
}
