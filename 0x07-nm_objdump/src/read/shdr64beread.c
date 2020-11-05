#include "../read.h"

/**
 * shdr64beread - read a 64-bit big-endian section header
 *
 * @shdr: pointer to a 64-bit big-endian section header
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int shdr64beread(Elf64_Shdr *shdr, FILE *istream)
{
	if (!shdr || !istream || fread(shdr, sizeof(*shdr), 1, istream) != 1)
		return (1);
	shdr64betoh(shdr);
	return (0);
}

