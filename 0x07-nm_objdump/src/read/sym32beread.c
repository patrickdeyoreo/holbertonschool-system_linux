#include "../read.h"

/**
 * sym32beread - read a 32-bit big-endian sym table entry
 *
 * @sym: pointer to a 32-bit big-endian sym table entry
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int sym32beread(Elf32_Sym *sym, FILE *istream)
{
	if (!sym || !istream || fread(sym, sizeof(*sym), 1, istream) != 1)
		return (1);
	sym32betoh(sym);
	return (0);
}

