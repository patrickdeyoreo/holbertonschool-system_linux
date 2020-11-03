#include "../load.h"

/**
 * verdaux32leload - load a 32-bit little-endian version info
 *
 * @filename: name of the input file
 * @verdaux: pointer to a 32-bit little-endian version info
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int verdaux32leload(const char *filename, Elf32_Verdaux *verdaux)
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
	verdaux32letoh(verdaux);
	return (0);
}

