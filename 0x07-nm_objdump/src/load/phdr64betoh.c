#include "../load.h"

/**
 * phdr64beload - load a 64-bit big-endian program header
 *
 * @filename: name of the input file
 * @phdr: pointer to a 64-bit big-endian program header
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int phdr64beload(const char *filename, Elf64_Phdr *phdr)
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
	phdr64betoh(phdr);
	return (0);
}

