#include "../read.h"

/**
 * verdaux32beread - read a 32-bit big-endian version info
 *
 * @verdaux: pointer to a 32-bit big-endian version info
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int verdaux32beread(Elf32_Verdaux *verdaux, FILE *istream)
{
	if (!verdaux || !istream || fread(verdaux, sizeof(*verdaux), 1, istream) != 1)
		return (1);
	verdaux32betoh(verdaux);
	return (0);
}

