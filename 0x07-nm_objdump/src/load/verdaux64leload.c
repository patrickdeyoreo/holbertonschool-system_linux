#include "../load.h"

/**
 * verdaux64leload - load a 64-bit little-endian version info
 *
 * @filename: name of the input file
 * @verdaux: pointer to a 64-bit little-endian version info
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int verdaux64leload(const char *filename, Elf64_Verdaux *verdaux)
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
	verdaux64letoh(verdaux);
	return (0);
}

