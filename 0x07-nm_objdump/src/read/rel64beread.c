#include "../read.h"

/**
 * rel64beread - read a 64-bit big-endian reloc tab entry
 *
 * @rel: pointer to a 64-bit big-endian reloc tab entry
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int rel64beread(Elf64_Rel *rel, FILE *istream)
{
	if (!rel || !istream || fread(rel, sizeof(*rel), 1, istream) != 1)
		return (1);
	rel64betoh(rel);
	return (0);
}

