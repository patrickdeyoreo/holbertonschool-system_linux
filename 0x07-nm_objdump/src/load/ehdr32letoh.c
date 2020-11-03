#include "../load.h"

/**
 * ehdr32leload - load a 32-bit little-endian ELF header
 *
 * @filename: name of the input file
 * @ehdr: pointer to a 32-bit little-endian ELF header
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int ehdr32leload(const char *filename, Elf32_Ehdr *ehdr)
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
	ehdr32letoh(ehdr);
	return (0);
}

