#include "../load.h"

/**
 * verneed64beload - load a 64-bit big-endian dep section
 *
 * @filename: name of the input file
 * @verneed: pointer to a 64-bit big-endian dep section
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int verneed64beload(const char *filename, Elf64_Verneed *verneed)
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
	verneed64betoh(verneed);
	return (0);
}

