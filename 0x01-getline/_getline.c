#include "_getline.h"

/**
 * _getline - find the first occurrence of a character in a string
 * @fd: file descriptor to read from
 * Return: NULL if an error occurs, otherwise a pointer to the string
 */
char *_getline(const int fd)
{
	static char *buf, *r_pos, *w_pos;
	ssize_t n_read = 0;
	char *line = NULL;

	if (!buf)
	{
		buf = malloc(sizeof(*buf) * READ_SIZE);
		if (!buf)
			return (NULL);
	}
	if (r_pos != w_pos)
	{
		return (NULL);
	}
	while ((n_read = read(fd, w_pos, READ_SIZE)) > 0)
	{
		w_pos += n_read;
		if (n_read < READ_SIZE)
		{
			return (NULL);
		}
	}
	if (n_read == -1)
	{
		free(line);
		return (NULL);
	}
	if (n_read == 0)
	{
		return (NULL);
	}
	return (line);
}
