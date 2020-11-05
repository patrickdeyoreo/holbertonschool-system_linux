#include "../read.h"

/**
 * lib64beread - read a 64-bit big-endian SHT_MIPS_LIBLIST entry
 *
 * @lib: pointer to a 64-bit big-endian SHT_MIPS_LIBLIST entry
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int lib64beread(Elf64_Lib *lib, FILE *istream)
{
	if (!lib || !istream || fread(lib, sizeof(*lib), 1, istream) != 1)
		return (1);
	lib64betoh(lib);
	return (0);
}

