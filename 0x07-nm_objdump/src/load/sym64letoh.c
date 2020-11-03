#include "../load.h"

/**
 * sym64leload - load a 64-bit little-endian sym table entry
 *
 * @filename: name of the input file
 * @sym: pointer to a 64-bit little-endian sym table entry
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int sym64leload(const char *filename, Elf64_Sym *sym)
{
	FILE *istream = filename && sym ? fopen(filename, "r") : NULL;

	if (!istream)
	{
		return (1);
	}
	if (fread(sym, sizeof(*sym), 1, istream) != 1)
	{
		fclose(istream);
		return (1);
	}
	fclose(istream);
	sym64letoh(sym);
	return (0);
}

