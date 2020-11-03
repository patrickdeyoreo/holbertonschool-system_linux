#include "../load.h"

/**
 * ehdr32beload - load a 32-bit big-endian ELF header
 *
 * @filename: name of the input file
 * @ehdr: pointer to a 32-bit big-endian ELF header
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int ehdr32beload(const char *filename, Elf32_Ehdr *ehdr)
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
	ehdr32betoh(ehdr);
	return (0);
}

