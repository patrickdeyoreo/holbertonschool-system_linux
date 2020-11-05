#include "../read.h"

/**
 * rel64leread - read a 64-bit little-endian reloc tab entry
 *
 * @rel: pointer to a 64-bit little-endian reloc tab entry
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int rel64leread(Elf64_Rel *rel, FILE *istream)
{
	if (!rel || !istream || fread(rel, sizeof(*rel), 1, istream) != 1)
		return (1);
	rel64letoh(rel);
	return (0);
}

