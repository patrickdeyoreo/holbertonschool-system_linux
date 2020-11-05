#include "../read.h"

/**
 * verneed64leread - read a 64-bit little-endian dep section
 *
 * @verneed: pointer to a 64-bit little-endian dep section
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int verneed64leread(Elf64_Verneed *verneed, FILE *istream)
{
	if (!verneed || !istream || fread(verneed, sizeof(*verneed), 1, istream) != 1)
		return (1);
	verneed64letoh(verneed);
	return (0);
}

