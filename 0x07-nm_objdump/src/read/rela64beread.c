#include "../read.h"

/**
 * rela64beread - read a 64-bit big-endian reloc w/ addend
 *
 * @rela: pointer to a 64-bit big-endian reloc w/ addend
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int rela64beread(Elf64_Rela *rela, FILE *istream)
{
	if (!rela || !istream || fread(rela, sizeof(*rela), 1, istream) != 1)
		return (1);
	rela64betoh(rela);
	return (0);
}

