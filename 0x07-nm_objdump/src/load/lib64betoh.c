#include "../load.h"

/**
 * lib64beload - load a 64-bit big-endian SHT_MIPS_LIBLIST entry
 *
 * @filename: name of the input file
 * @lib: pointer to a 64-bit big-endian SHT_MIPS_LIBLIST entry
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int lib64beload(const char *filename, Elf64_Lib *lib)
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
	lib64betoh(lib);
	return (0);
}

