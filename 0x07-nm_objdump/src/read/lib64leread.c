#include "../read.h"

/**
 * lib64leread - read a 64-bit little-endian SHT_MIPS_LIBLIST entry
 *
 * @lib: pointer to a 64-bit little-endian SHT_MIPS_LIBLIST entry
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int lib64leread(Elf64_Lib *lib, FILE *istream)
{
	if (!lib || !istream || fread(lib, sizeof(*lib), 1, istream) != 1)
		return (1);
	lib64letoh(lib);
	return (0);
}

