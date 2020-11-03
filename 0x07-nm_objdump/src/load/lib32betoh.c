#include "../load.h"

/**
 * lib32beload - load a 32-bit big-endian SHT_MIPS_LIBLIST entry
 *
 * @filename: name of the input file
 * @lib: pointer to a 32-bit big-endian SHT_MIPS_LIBLIST entry
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int lib32beload(const char *filename, Elf32_Lib *lib)
{
	FILE *istream = filename && lib ? fopen(filename, "r") : NULL;

	if (!istream)
	{
		return (1);
	}
	if (fread(lib, sizeof(*lib), 1, istream) != 1)
	{
		fclose(istream);
		return (1);
	}
	fclose(istream);
	lib32betoh(lib);
	return (0);
}

