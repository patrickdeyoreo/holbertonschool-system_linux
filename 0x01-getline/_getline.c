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
	ssize_t n_read = 0, len = 0;
	size_t n = 0;

	if (fd < 0)
		return (NULL);

	if (_getline_line(&buf, &len, &line, &n))
		return (line);

	while ((n_read = read(fd, buf.w_pos, buf.buffer + READ_SIZE - buf.w_pos)))
	{
		if (n_read == -1)
		{
			free(line);
			return (NULL);
		}
		buf.w_pos += n_read;

		if (_getline_line(&buf, &len, &line, &n))
			return (line);

		if (_getline_full(&buf, &len, &line, &n) == -1)
			return (NULL);
	}
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
 * Return: If memory allocation fails, return -1. If a line is not found,
 * return 0. Otherwise, return the total length of the line.
 */
ssize_t _getline_line(buf_t *buf, ssize_t *len, char **line, size_t *n)
{
	char *new = NULL;
	ssize_t eol = _strnchr(buf->r_pos, '\n', buf->w_pos - buf->r_pos);

	if (eol == -1)
		return (0);

	if (*n < (size_t) *len + eol + 2)
	{
		if (*line)
			new = _realloc(*line, *n, sizeof(char) * (*len + eol + 2));
		else
			new = malloc(sizeof(char) * (*len + eol + 2));

		if (!new)
		{
			free(*line);
			*line = NULL;
			*n = 0;
			return ((*len = -1));
		}
		*line = new;
		*n = *len + eol + 2;
	}
	_memcpy(*line + *len, buf->r_pos, eol + 1);
	(*line)[*len + eol + 1] = '\0';

	*len += eol + 1;

	if (buf->r_pos + eol + 1 < buf->w_pos)
		buf->r_pos += eol + 1;
	else
		buf->r_pos = buf->w_pos = buf->buffer;

	return (*len);
}


/**
 * _getline_full - copy the whole buffer
 * @buf: pointer to the buffer structure to read from
 * @len: pointer to the current line length
 * @line: pointer to the line buffer
 * @n: pointer to the size of the line buffer
 * Return: If memory allocation fails, return -1. Otherwise, return the total
 * length of the line.
 */
ssize_t _getline_full(buf_t *buf, ssize_t *len, char **line, size_t *n)
{
	char *new = NULL;
	size_t n_remaining = buf->w_pos - buf->r_pos;

	if (*n <= (size_t) *len + n_remaining)
	{
		if (*line)
			new = _realloc(*line, *n, sizeof(char) * (*len + n_remaining + 1));
		else
			new = malloc(sizeof(char) * (*len + n_remaining + 1));

		if (!new)
		{
			free(*line);
			*line = NULL;
			*n = 0;
			return ((*len = -1));
		}
		*line = new;
		*n = *len + n_remaining + 1;
	}
	_memcpy(*line + *len, buf->r_pos, n_remaining);
	(*line)[*len + n_remaining] = '\0';

	*len += n_remaining;

	buf->r_pos = buf->w_pos = buf->buffer;

	return (*len);
}


/**
  * _strnchr - get the index of the first matching character
  * @str: string passed
  * @c: character passed
  * @n: max number of characters to check
  * Return: Index of the first occurence, or -1 c is not found
  */
ssize_t _strnchr(const char *str, char c, size_t n)
{
	ssize_t index;

	if (!str)
		return (-1);

	for (index = 0; n && str[index]; --n, ++index)
	{
		if (str[index] == c)
			return (index);
	}

	return (-1);
}

/**
 * _realloc - reallocate a buffer
 * @buffer: pointer to the buffer
 * @old_size: current size of the buffer
 * @new_size: desired size of the buffer
 * Return: NULL if memory allocation fails, otherwise a pointer to the new buffer
 */
void *_realloc(void *buffer, size_t old_size, size_t new_size)
{
	unsigned char *src = buffer;
	unsigned char *dest = NULL;

	if (src)
		dest = malloc(sizeof(*dest) * new_size);

	buffer = dest;

	if (dest)
	{
		while (old_size && new_size)
		{
			*dest++ = *src++;
			old_size -= 1;
			new_size -= 1;
		}
		while (new_size)
		{
			*dest++ = '\0';
			new_size -= 1;
		}
	}
	return (buffer);
}