#include "../load.h"

/**
 * sym32leload - load a 32-bit little-endian sym table entry
 *
 * @filename: name of the input file
 * @sym: pointer to a 32-bit little-endian sym table entry
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int sym32leload(const char *filename, Elf32_Sym *sym)
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
	sym32letoh(sym);
	return (0);
}

