#include "../load.h"

/**
 * vernaux32leload - load a 32-bit little-endian req info
 *
 * @filename: name of the input file
 * @vernaux: pointer to a 32-bit little-endian req info
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int vernaux32leload(const char *filename, Elf32_Vernaux *vernaux)
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
	vernaux32letoh(vernaux);
	return (0);
}

