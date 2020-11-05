#include "../read.h"

/**
 * shdr32beread - read a 32-bit big-endian section header
 *
 * @shdr: pointer to a 32-bit big-endian section header
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int shdr32beread(Elf32_Shdr *shdr, FILE *istream)
{
	if (!shdr || !istream || fread(shdr, sizeof(*shdr), 1, istream) != 1)
		return (1);
	shdr32betoh(shdr);
	return (0);
}

