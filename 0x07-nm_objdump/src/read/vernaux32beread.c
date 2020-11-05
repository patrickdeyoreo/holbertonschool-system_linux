#include "../read.h"

/**
 * vernaux32beread - read a 32-bit big-endian req info
 *
 * @vernaux: pointer to a 32-bit big-endian req info
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int vernaux32beread(Elf32_Vernaux *vernaux, FILE *istream)
{
	if (!vernaux || !istream || fread(vernaux, sizeof(*vernaux), 1, istream) != 1)
		return (1);
	vernaux32betoh(vernaux);
	return (0);
}

