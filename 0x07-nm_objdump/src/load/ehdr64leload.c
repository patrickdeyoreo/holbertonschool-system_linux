#include "../load.h"

/**
 * ehdr64leload - load a 64-bit little-endian ELF header
 *
 * @filename: name of the input file
 * @ehdr: pointer to a 64-bit little-endian ELF header
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int ehdr64leload(const char *filename, Elf64_Ehdr *ehdr)
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
	ehdr64letoh(ehdr);
	return (0);
}

