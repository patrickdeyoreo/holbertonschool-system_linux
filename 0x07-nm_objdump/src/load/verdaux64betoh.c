#include "../load.h"

/**
 * verdaux64beload - load a 64-bit big-endian version info
 *
 * @filename: name of the input file
 * @verdaux: pointer to a 64-bit big-endian version info
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int verdaux64beload(const char *filename, Elf64_Verdaux *verdaux)
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
	verdaux64betoh(verdaux);
	return (0);
}

