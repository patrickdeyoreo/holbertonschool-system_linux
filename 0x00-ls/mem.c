#include "mem.h"

/**
 * _memcmp - lexicographically compare two memory areas
 * @base1: the start of the first memory area
 * @base2: the start of the other memory area
 * @n: the number of bytes to swap
 *
 * Description: Compare n bytes of the memory areas base1 and base2.
 *
 * Return: an integer less than, equal to, or greater than zero if the contents
 * of base1 is, respectively, less than, equal to, or greater than the contents
 * of base2.
 */
int _memcmp(const void *base1, const void *base2, size_t n)
{
	const unsigned char *byte1 = base1, *byte2 = base2;
	int diff = 0;

	if (base1 && base2)
	{
		while (!diff && n--)
			diff = *byte1++ - *byte2++;
	}
	return (diff);
}

/**
 * _memcpy - copy a memory area
 * @src: the start of the source memory area
 * @dest: the start of the destination memory area
 * @n: the number of bytes to copy
 *
 * Description: Copy n bytes from the memory area src to the memory area dest.
 * The memory areas must not overlap.
 *
 * Return: a pointer to dest
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *byte_dest = dest;
	const unsigned char *byte_src = src;

	if (dest && src)
	{
		while (n--)
			byte_dest[n] = byte_src[n];
	}
	return (dest);
}

/**
 * _memswap - swap two memory areas
 * @base1: the start of the first memory area
 * @base2: the start of the other memory area
 * @n: the number of bytes to swap
 *
 * Description: Swap n bytes between the memory areas base1 and base2.
 * The memory areas must not overlap.
 */
void _memswap(void *base1, void *base2, size_t n)
{
	unsigned char *byte1 = base1, *byte2 = base2;

	if (base1 && base2)
	{
		while (n--)
		{
			byte1[n] ^= byte2[n];
			byte2[n] ^= byte1[n];
			byte1[n] ^= byte2[n];
		}
	}
}
