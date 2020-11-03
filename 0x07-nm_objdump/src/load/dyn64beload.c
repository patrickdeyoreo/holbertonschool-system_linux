#include "../load.h"

/**
 * dyn64beload - load a 64-bit big-endian dyn entry
 *
 * @filename: name of the input file
 * @dyn: pointer to a 64-bit big-endian dyn entry
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int dyn64beload(const char *filename, Elf64_Dyn *dyn)
{
	FILE *istream = filename && dyn ? fopen(filename, "r") : NULL;

	if (!istream)
	{
		return (1);
	}
	if (fread(dyn, sizeof(*dyn), 1, istream) != 1)
	{
		fclose(istream);
		return (1);
	}
	fclose(istream);
	dyn64betoh(dyn);
	return (0);
}

