#include "_getline.h"

/**
 * _getline - read a line of input
 * @fd: file descriptor to read from
 * Return: NULL if an error occurs, otherwise a pointer to the line
 */
char *_getline(const int fd)
{
	static buf_t buf = {{0}, buf.buffer, buf.buffer};
	char *line = NULL;
	size_t n = 0;
	ssize_t len = 0;
	ssize_t n_read = 0;

	if (fd < 0)
		return (NULL);

	do {
		if (n_read == -1)
			return (free(line), NULL);

		if (n_read)
			buf.w_pos = buf.buffer + n_read;

		if (_getline_line(&buf, &len, &line, &n))
			return (line);

		if (_getline_full(&buf, &len, &line, &n) == -1)
			return (NULL);

	} while ((n_read = read(fd, buf.buffer, READ_SIZE)));

	if (!line)
		line = malloc(sizeof(*line));

	if (line)
		line[len] = '\0';

	return (line);
}


/**
 * _getline_line - get a line from the buffer
 * @buf: pointer to the buffer structure to read from
 * @len: pointer to the current line length
 * @line: pointer to the line buffer
 * @n: pointer to the size of the line buffer
 * Return: If memory allocation fails, return -1.
 * If a line terminator ('\n') is not found, return 0.
 * Otherwise, return the total length of the line.
 */
ssize_t _getline_line(buf_t *buf, ssize_t *len, char **line, size_t *n)
{
	char *new = NULL;
	ssize_t eol = _strnchr(buf->r_pos, '\n', buf->w_pos - buf->r_pos);

	if (eol == -1)
		return (0);

	if (*n < (size_t) (*len + eol + 2))
	{
		if (*line)
			new = _realloc((void *) *line, sizeof(**line) * (*n), sizeof(**line) * (*len + eol + 2));
		else
			new = malloc(sizeof(**line) * (*len + eol + 2));

		if (!new)
		{
			free(*line);
			*line = NULL;
			*n = 0;
			*len = (-1);
			return (-1);
		}
		*line = new;
		*n = *len + eol + 2;
	}
	memcpy(*line + *len, buf->r_pos, eol + 1);
	(*line)[(*len += eol + 1)] = '\0';

	buf->r_pos += eol + 1;
	if (buf->w_pos < buf->r_pos + 1)
		buf->w_pos = buf->r_pos = buf->buffer;

	return (*len);
}


/**
 * _getline_full - copy the whole buffer
 * @buf: pointer to the buffer structure to read from
 * @len: pointer to the current line length
 * @line: pointer to the line buffer
 * @n: pointer to the size of the line buffer
 * Return: If memory allocation fails, return -1.
 * Otherwise, return the total length of the line.
 */
ssize_t _getline_full(buf_t *buf, ssize_t *len, char **line, size_t *n)
{
	char *new = NULL;
	size_t rem = buf->w_pos - buf->r_pos;

	if (*n < (size_t) (*len + rem + 1))
	{
		if (*line)
			new = _realloc((void *) *line, sizeof(**line) * (*n), sizeof(**line) * (*len + rem + 1));
		else
			new = malloc(sizeof(**line) * (*len + rem + 1));

		if (!new)
		{
			free(*line);
			*line = NULL;
			*n = 0;
			*len = (-1);
			return (-1);
		}
		*line = new;
		*n = *len + rem + 1;
	}
	memcpy(*line + *len, buf->r_pos, rem);
	(*line)[(*len += rem)] = '\0';

	buf->w_pos = buf->r_pos = buf->buffer;

	return (*len);
}


/**
  * _strnchr - get the index of the first matching character
  * @s: string passed
  * @c: character passed
  * @n: max number of characters to check
  * Return: Index of the first occurence, or -1 c is not found
  */
ssize_t _strnchr(const char *s, char c, size_t n)
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
void *_realloc(void *old, size_t old_size, size_t new_size)
{
	unsigned char *src = old, *dest = NULL;
	void *new = NULL;

	if (old)
		dest = new = malloc(sizeof(*new) * new_size);

	if (new)
	{
		while (old_size-- && new_size--)
			*dest++ = *src++;
		free(old);
	}
	return (new);
}