#include "../read.h"

/**
 * shdr64leread - read a 64-bit little-endian section header
 *
 * @shdr: pointer to a 64-bit little-endian section header
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int shdr64leread(Elf64_Shdr *shdr, FILE *istream)
{
	if (!shdr || !istream || fread(shdr, sizeof(*shdr), 1, istream) != 1)
		return (1);
	shdr64letoh(shdr);
	return (0);
}

