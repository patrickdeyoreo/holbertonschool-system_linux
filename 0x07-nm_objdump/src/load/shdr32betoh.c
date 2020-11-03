#include "../load.h"

/**
 * shdr32beload - load a 32-bit big-endian section header
 *
 * @filename: name of the input file
 * @shdr: pointer to a 32-bit big-endian section header
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int shdr32beload(const char *filename, Elf32_Shdr *shdr)
{
	FILE *istream = filename && shdr ? fopen(filename, "r") : NULL;

	if (!istream)
	{
		return (1);
	}
	if (fread(shdr, sizeof(*shdr), 1, istream) != 1)
	{
		fclose(istream);
		return (1);
	}
	fclose(istream);
	shdr32betoh(shdr);
	return (0);
}

