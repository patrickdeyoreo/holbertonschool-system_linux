#include "../load.h"

/**
 * dyn32leload - load a 32-bit little-endian dyn entry
 *
 * @filename: name of the input file
 * @dyn: pointer to a 32-bit little-endian dyn entry
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int dyn32leload(const char *filename, Elf32_Dyn *dyn)
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
	dyn32letoh(dyn);
	return (0);
}

