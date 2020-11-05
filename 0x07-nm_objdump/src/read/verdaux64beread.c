#include "../read.h"

/**
 * verdaux64beread - read a 64-bit big-endian version info
 *
 * @verdaux: pointer to a 64-bit big-endian version info
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int verdaux64beread(Elf64_Verdaux *verdaux, FILE *istream)
{
	if (!verdaux || !istream || fread(verdaux, sizeof(*verdaux), 1, istream) != 1)
		return (1);
	verdaux64betoh(verdaux);
	return (0);
}

