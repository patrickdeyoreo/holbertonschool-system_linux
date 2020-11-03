#include "../load.h"

/**
 * ehdr64beload - load a 64-bit big-endian ELF header
 *
 * @filename: name of the input file
 * @ehdr: pointer to a 64-bit big-endian ELF header
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int ehdr64beload(const char *filename, Elf64_Ehdr *ehdr)
{
	FILE *istream = filename && ehdr ? fopen(filename, "r") : NULL;

	if (!istream)
	{
		return (1);
	}
	if (fread(ehdr, sizeof(*ehdr), 1, istream) != 1)
	{
		fclose(istream);
		return (1);
	}
	fclose(istream);
	ehdr64betoh(ehdr);
	return (0);
}

