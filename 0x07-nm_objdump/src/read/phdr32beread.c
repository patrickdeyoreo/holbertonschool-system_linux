#include "../read.h"

/**
 * phdr32beread - read a 32-bit big-endian program header
 *
 * @phdr: pointer to a 32-bit big-endian program header
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int phdr32beread(Elf32_Phdr *phdr, FILE *istream)
{
	if (!phdr || !istream || fread(phdr, sizeof(*phdr), 1, istream) != 1)
		return (1);
	phdr32betoh(phdr);
	return (0);
}

