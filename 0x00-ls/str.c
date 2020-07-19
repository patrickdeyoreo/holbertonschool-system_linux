#include "str.h"

/**
 * _strlen - measure the length of a string
 * @s: a pointer to the string
 *
 * Return: the length of the string
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	if (s)
	{
		while (*s++)
			len += 1;
	}
	return (len);
}
