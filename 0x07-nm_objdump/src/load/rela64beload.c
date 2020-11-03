#include "../load.h"

/**
 * rela64beload - load a 64-bit big-endian reloc w/ addend
 *
 * @filename: name of the input file
 * @rela: pointer to a 64-bit big-endian reloc w/ addend
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int rela64beload(const char *filename, Elf64_Rela *rela)
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
	rela64betoh(rela);
	return (0);
}

