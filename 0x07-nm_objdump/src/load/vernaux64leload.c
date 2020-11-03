#include "../load.h"

/**
 * vernaux64leload - load a 64-bit little-endian req info
 *
 * @filename: name of the input file
 * @vernaux: pointer to a 64-bit little-endian req info
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int vernaux64leload(const char *filename, Elf64_Vernaux *vernaux)
{
	FILE *istream = filename && vernaux ? fopen(filename, "r") : NULL;

	if (!istream)
	{
		return (1);
	}
	if (fread(vernaux, sizeof(*vernaux), 1, istream) != 1)
	{
		fclose(istream);
		return (1);
	}
	fclose(istream);
	vernaux64letoh(vernaux);
	return (0);
}

