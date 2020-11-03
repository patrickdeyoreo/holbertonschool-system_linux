#include "../load.h"

/**
 * shdr64leload - load a 64-bit little-endian section header
 *
 * @filename: name of the input file
 * @shdr: pointer to a 64-bit little-endian section header
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int shdr64leload(const char *filename, Elf64_Shdr *shdr)
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
	shdr64letoh(shdr);
	return (0);
}

