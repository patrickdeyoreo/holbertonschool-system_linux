#include "../load.h"

/**
 * vernaux32beload - load a 32-bit big-endian req info
 *
 * @filename: name of the input file
 * @vernaux: pointer to a 32-bit big-endian req info
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int vernaux32beload(const char *filename, Elf32_Vernaux *vernaux)
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
	vernaux32betoh(vernaux);
	return (0);
}

