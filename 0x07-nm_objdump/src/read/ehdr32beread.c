#include "../read.h"

/**
 * ehdr32beread - read a 32-bit big-endian ELF header
 *
 * @ehdr: pointer to a 32-bit big-endian ELF header
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int ehdr32beread(Elf32_Ehdr *ehdr, FILE *istream)
{
	if (!ehdr || !istream || fread(ehdr, sizeof(*ehdr), 1, istream) != 1)
		return (1);
	ehdr32betoh(ehdr);
	return (0);
}

