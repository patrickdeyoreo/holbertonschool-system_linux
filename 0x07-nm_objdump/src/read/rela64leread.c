#include "../read.h"

/**
 * rela64leread - read a 64-bit little-endian reloc w/ addend
 *
 * @rela: pointer to a 64-bit little-endian reloc w/ addend
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int rela64leread(Elf64_Rela *rela, FILE *istream)
{
	if (!rela || !istream || fread(rela, sizeof(*rela), 1, istream) != 1)
		return (1);
	rela64letoh(rela);
	return (0);
}

