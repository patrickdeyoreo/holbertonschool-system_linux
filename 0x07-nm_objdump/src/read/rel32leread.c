#include "../read.h"

/**
 * rel32leread - read a 32-bit little-endian reloc tab entry
 *
 * @rel: pointer to a 32-bit little-endian reloc tab entry
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int rel32leread(Elf32_Rel *rel, FILE *istream)
{
	if (!rel || !istream || fread(rel, sizeof(*rel), 1, istream) != 1)
		return (1);
	rel32letoh(rel);
	return (0);
}

