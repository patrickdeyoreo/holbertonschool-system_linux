#include "../read.h"

/**
 * sym64beread - read a 64-bit big-endian sym table entry
 *
 * @sym: pointer to a 64-bit big-endian sym table entry
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int sym64beread(Elf64_Sym *sym, FILE *istream)
{
	if (!sym || !istream || fread(sym, sizeof(*sym), 1, istream) != 1)
		return (1);
	sym64betoh(sym);
	return (0);
}

