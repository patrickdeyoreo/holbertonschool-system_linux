#include "strn.h"

/**
 * _strnlen - measure the length of a string up to n characters
 * @s: a pointer to the string
 * @n: the maximum number of characters
 *
 * Return: the length of the string or n, whichever is less
 */
size_t _strnlen(const char *s, size_t n)
{
	size_t len = 0;

	if (s)
	{
		while (n-- && *s++)
			len += 1;
	}
	return (len);
}
