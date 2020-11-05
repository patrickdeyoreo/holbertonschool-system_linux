#include "../read.h"

/**
 * lib32beread - read a 32-bit big-endian SHT_MIPS_LIBLIST entry
 *
 * @lib: pointer to a 32-bit big-endian SHT_MIPS_LIBLIST entry
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int lib32beread(Elf32_Lib *lib, FILE *istream)
{
	if (!lib || !istream || fread(lib, sizeof(*lib), 1, istream) != 1)
		return (1);
	lib32betoh(lib);
	return (0);
}

