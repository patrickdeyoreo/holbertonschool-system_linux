#include <ctype.h>
#include <string.h>

#include "util.h"

/**
 * trimwhitespace - trim leading and trailing whitespace
 *
 * @str: pointer to the string to trim
 *
 * Return: pointer to a substring of str with whitespace trimmed
 */
char *trimwhitespace(char *str)
{
	char *end = NULL;

	while (isspace(*str))
		str += 1;

	if (*str)
	{
		end = str + strlen(str) - 1;
		while (end > str && isspace(*end))
			end -= 1;

		end[1] = '\0';
	}
	return (str);
}
