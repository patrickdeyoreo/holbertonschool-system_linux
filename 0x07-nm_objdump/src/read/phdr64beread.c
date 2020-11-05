#include "../read.h"

/**
 * phdr64beread - read a 64-bit big-endian program header
 *
 * @phdr: pointer to a 64-bit big-endian program header
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int phdr64beread(Elf64_Phdr *phdr, FILE *istream)
{
	if (!phdr || !istream || fread(phdr, sizeof(*phdr), 1, istream) != 1)
		return (1);
	phdr64betoh(phdr);
	return (0);
}

