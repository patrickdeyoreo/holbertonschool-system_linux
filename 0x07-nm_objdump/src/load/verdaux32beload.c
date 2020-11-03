#include "../load.h"

/**
 * verdaux32beload - load a 32-bit big-endian version info
 *
 * @filename: name of the input file
 * @verdaux: pointer to a 32-bit big-endian version info
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int verdaux32beload(const char *filename, Elf32_Verdaux *verdaux)
{
	FILE *istream = filename && verdaux ? fopen(filename, "r") : NULL;

	if (!istream)
	{
		return (1);
	}
	if (fread(verdaux, sizeof(*verdaux), 1, istream) != 1)
	{
		fclose(istream);
		return (1);
	}
	fclose(istream);
	verdaux32betoh(verdaux);
	return (0);
}

