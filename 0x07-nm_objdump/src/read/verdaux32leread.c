#include "../read.h"

/**
 * verdaux32leread - read a 32-bit little-endian version info
 *
 * @verdaux: pointer to a 32-bit little-endian version info
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int verdaux32leread(Elf32_Verdaux *verdaux, FILE *istream)
{
	if (!verdaux || !istream || fread(verdaux, sizeof(*verdaux), 1, istream) != 1)
		return (1);
	verdaux32letoh(verdaux);
	return (0);
}

