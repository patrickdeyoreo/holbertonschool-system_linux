#include "../read.h"

/**
 * dyn32beread - read a 32-bit big-endian dyn entry
 *
 * @dyn: pointer to a 32-bit big-endian dyn entry
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int dyn32beread(Elf32_Dyn *dyn, FILE *istream)
{
	if (!dyn || !istream || fread(dyn, sizeof(*dyn), 1, istream) != 1)
		return (1);
	dyn32betoh(dyn);
	return (0);
}

