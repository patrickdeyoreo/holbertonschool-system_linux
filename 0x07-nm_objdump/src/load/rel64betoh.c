#include "../load.h"

/**
 * rel64beload - load a 64-bit big-endian reloc tab entry
 *
 * @filename: name of the input file
 * @rel: pointer to a 64-bit big-endian reloc tab entry
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int rel64beload(const char *filename, Elf64_Rel *rel)
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
	rel64betoh(rel);
	return (0);
}

