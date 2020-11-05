#include "../read.h"

/**
 * verneed64beread - read a 64-bit big-endian dep section
 *
 * @verneed: pointer to a 64-bit big-endian dep section
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int verneed64beread(Elf64_Verneed *verneed, FILE *istream)
{
	if (!verneed || !istream || fread(verneed, sizeof(*verneed), 1, istream) != 1)
		return (1);
	verneed64betoh(verneed);
	return (0);
}

