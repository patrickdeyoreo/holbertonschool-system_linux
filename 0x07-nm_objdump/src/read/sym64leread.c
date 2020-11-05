#include "../read.h"

/**
 * sym64leread - read a 64-bit little-endian sym table entry
 *
 * @sym: pointer to a 64-bit little-endian sym table entry
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int sym64leread(Elf64_Sym *sym, FILE *istream)
{
	if (!sym || !istream || fread(sym, sizeof(*sym), 1, istream) != 1)
		return (1);
	sym64letoh(sym);
	return (0);
}

