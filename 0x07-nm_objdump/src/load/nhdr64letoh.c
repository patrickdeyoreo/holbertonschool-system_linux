#include "../load.h"

/**
 * nhdr64leload - load a 64-bit little-endian note header
 *
 * @filename: name of the input file
 * @nhdr: pointer to a 64-bit little-endian note header
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int nhdr64leload(const char *filename, Elf64_Nhdr *nhdr)
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
	nhdr64letoh(nhdr);
	return (0);
}

