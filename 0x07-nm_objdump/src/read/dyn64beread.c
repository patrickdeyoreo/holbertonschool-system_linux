#include "../read.h"

/**
 * dyn64beread - read a 64-bit big-endian dyn entry
 *
 * @dyn: pointer to a 64-bit big-endian dyn entry
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int dyn64beread(Elf64_Dyn *dyn, FILE *istream)
{
	if (!dyn || !istream || fread(dyn, sizeof(*dyn), 1, istream) != 1)
		return (1);
	dyn64betoh(dyn);
	return (0);
}

