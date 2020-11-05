#include "../read.h"

/**
 * vernaux64leread - read a 64-bit little-endian req info
 *
 * @vernaux: pointer to a 64-bit little-endian req info
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int vernaux64leread(Elf64_Vernaux *vernaux, FILE *istream)
{
	if (!vernaux || !istream || fread(vernaux, sizeof(*vernaux), 1, istream) != 1)
		return (1);
	vernaux64letoh(vernaux);
	return (0);
}

