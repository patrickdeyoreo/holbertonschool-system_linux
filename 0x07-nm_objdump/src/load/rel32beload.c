#include "../load.h"

/**
 * rel32beload - load a 32-bit big-endian reloc tab entry
 *
 * @filename: name of the input file
 * @rel: pointer to a 32-bit big-endian reloc tab entry
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int rel32beload(const char *filename, Elf32_Rel *rel)
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
	rel32betoh(rel);
	return (0);
}

