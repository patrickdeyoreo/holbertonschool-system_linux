#include "../load.h"

/**
 * nhdr32leload - load a 32-bit little-endian note header
 *
 * @filename: name of the input file
 * @nhdr: pointer to a 32-bit little-endian note header
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int nhdr32leload(const char *filename, Elf32_Nhdr *nhdr)
{
	FILE *istream = filename && nhdr ? fopen(filename, "r") : NULL;

	if (!istream)
	{
		return (1);
	}
	if (fread(nhdr, sizeof(*nhdr), 1, istream) != 1)
	{
		fclose(istream);
		return (1);
	}
	fclose(istream);
	nhdr32letoh(nhdr);
	return (0);
}

