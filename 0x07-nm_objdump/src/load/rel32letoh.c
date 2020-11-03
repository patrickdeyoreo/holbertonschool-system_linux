#include "../load.h"

/**
 * rel32leload - load a 32-bit little-endian reloc tab entry
 *
 * @filename: name of the input file
 * @rel: pointer to a 32-bit little-endian reloc tab entry
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int rel32leload(const char *filename, Elf32_Rel *rel)
{
	FILE *istream = filename && rel ? fopen(filename, "r") : NULL;

	if (!istream)
	{
		return (1);
	}
	if (fread(rel, sizeof(*rel), 1, istream) != 1)
	{
		fclose(istream);
		return (1);
	}
	fclose(istream);
	rel32letoh(rel);
	return (0);
}

