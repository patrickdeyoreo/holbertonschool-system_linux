#include "../read.h"

/**
 * sym32leread - read a 32-bit little-endian sym table entry
 *
 * @sym: pointer to a 32-bit little-endian sym table entry
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int sym32leread(Elf32_Sym *sym, FILE *istream)
{
	if (!sym || !istream || fread(sym, sizeof(*sym), 1, istream) != 1)
		return (1);
	sym32letoh(sym);
	return (0);
}

