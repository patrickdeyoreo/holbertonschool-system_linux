#include "../read.h"

/**
 * dyn32leread - read a 32-bit little-endian dyn entry
 *
 * @dyn: pointer to a 32-bit little-endian dyn entry
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int dyn32leread(Elf32_Dyn *dyn, FILE *istream)
{
	if (!dyn || !istream || fread(dyn, sizeof(*dyn), 1, istream) != 1)
		return (1);
	dyn32letoh(dyn);
	return (0);
}

