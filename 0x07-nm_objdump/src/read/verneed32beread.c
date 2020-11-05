#include "../read.h"

/**
 * verneed32beread - read a 32-bit big-endian dep section
 *
 * @verneed: pointer to a 32-bit big-endian dep section
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int verneed32beread(Elf32_Verneed *verneed, FILE *istream)
{
	if (!verneed || !istream || fread(verneed, sizeof(*verneed), 1, istream) != 1)
		return (1);
	verneed32betoh(verneed);
	return (0);
}

