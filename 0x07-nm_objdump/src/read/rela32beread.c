#include "../read.h"

/**
 * rela32beread - read a 32-bit big-endian reloc w/ addend
 *
 * @rela: pointer to a 32-bit big-endian reloc w/ addend
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int rela32beread(Elf32_Rela *rela, FILE *istream)
{
	if (!rela || !istream || fread(rela, sizeof(*rela), 1, istream) != 1)
		return (1);
	rela32betoh(rela);
	return (0);
}

