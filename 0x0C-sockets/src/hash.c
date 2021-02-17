#include "hash.h"

/**
 * dbj2 - compute a hash using the djb2 algorithm
 *
 * @s: string to hash
 *
 * Return: hash of s
 */
unsigned long int dbj2(const char *s)
{
	unsigned long int hash = 5381;
	unsigned int c = 0;

	while ((c = *s++))
		hash += (hash << 5) + c;
	return (hash);
}
