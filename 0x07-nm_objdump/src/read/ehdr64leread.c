#include "../read.h"

/**
 * ehdr64leread - read a 64-bit little-endian ELF header
 *
 * @ehdr: pointer to a 64-bit little-endian ELF header
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int ehdr64leread(Elf64_Ehdr *ehdr, FILE *istream)
{
	if (!ehdr || !istream || fread(ehdr, sizeof(*ehdr), 1, istream) != 1)
		return (1);
	ehdr64letoh(ehdr);
	return (0);
}

