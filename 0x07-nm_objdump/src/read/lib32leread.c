#include "../read.h"

/**
 * lib32leread - read a 32-bit little-endian SHT_MIPS_LIBLIST entry
 *
 * @lib: pointer to a 32-bit little-endian SHT_MIPS_LIBLIST entry
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int lib32leread(Elf32_Lib *lib, FILE *istream)
{
	if (!lib || !istream || fread(lib, sizeof(*lib), 1, istream) != 1)
		return (1);
	lib32letoh(lib);
	return (0);
}

