#include "../read.h"

/**
 * dyn64leread - read a 64-bit little-endian dyn entry
 *
 * @dyn: pointer to a 64-bit little-endian dyn entry
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int dyn64leread(Elf64_Dyn *dyn, FILE *istream)
{
	if (!dyn || !istream || fread(dyn, sizeof(*dyn), 1, istream) != 1)
		return (1);
	dyn64letoh(dyn);
	return (0);
}

