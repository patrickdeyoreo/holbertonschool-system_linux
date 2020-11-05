#include "../read.h"

/**
 * ehdr64beread - read a 64-bit big-endian ELF header
 *
 * @ehdr: pointer to a 64-bit big-endian ELF header
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int ehdr64beread(Elf64_Ehdr *ehdr, FILE *istream)
{
	if (!ehdr || !istream || fread(ehdr, sizeof(*ehdr), 1, istream) != 1)
		return (1);
	ehdr64betoh(ehdr);
	return (0);
}

