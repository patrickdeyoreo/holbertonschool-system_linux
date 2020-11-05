#include "../read.h"

/**
 * vernaux32leread - read a 32-bit little-endian req info
 *
 * @vernaux: pointer to a 32-bit little-endian req info
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int vernaux32leread(Elf32_Vernaux *vernaux, FILE *istream)
{
	if (!vernaux || !istream || fread(vernaux, sizeof(*vernaux), 1, istream) != 1)
		return (1);
	vernaux32letoh(vernaux);
	return (0);
}

