#include "../load.h"

/**
 * phdr32leload - load a 32-bit little-endian program header
 *
 * @filename: name of the input file
 * @phdr: pointer to a 32-bit little-endian program header
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int phdr32leload(const char *filename, Elf32_Phdr *phdr)
{
	FILE *istream = filename && phdr ? fopen(filename, "r") : NULL;

	if (!istream)
	{
		return (1);
	}
	if (fread(phdr, sizeof(*phdr), 1, istream) != 1)
	{
		fclose(istream);
		return (1);
	}
	fclose(istream);
	phdr32letoh(phdr);
	return (0);
}

