#include "../load.h"

/**
 * verneed32leload - load a 32-bit little-endian dep section
 *
 * @filename: name of the input file
 * @verneed: pointer to a 32-bit little-endian dep section
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int verneed32leload(const char *filename, Elf32_Verneed *verneed)
{
	FILE *istream = filename && verneed ? fopen(filename, "r") : NULL;

	if (!istream)
	{
		return (1);
	}
	if (fread(verneed, sizeof(*verneed), 1, istream) != 1)
	{
		fclose(istream);
		return (1);
	}
	fclose(istream);
	verneed32letoh(verneed);
	return (0);
}

