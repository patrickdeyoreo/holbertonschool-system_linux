#include "../load.h"

/**
 * rela32beload - load a 32-bit big-endian reloc w/ addend
 *
 * @filename: name of the input file
 * @rela: pointer to a 32-bit big-endian reloc w/ addend
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int rela32beload(const char *filename, Elf32_Rela *rela)
{
	FILE *istream = filename && rela ? fopen(filename, "r") : NULL;

	if (!istream)
	{
		return (1);
	}
	if (fread(rela, sizeof(*rela), 1, istream) != 1)
	{
		fclose(istream);
		return (1);
	}
	fclose(istream);
	rela32betoh(rela);
	return (0);
}

