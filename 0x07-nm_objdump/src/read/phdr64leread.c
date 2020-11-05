#include "../read.h"

/**
 * phdr64leread - read a 64-bit little-endian program header
 *
 * @phdr: pointer to a 64-bit little-endian program header
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int phdr64leread(Elf64_Phdr *phdr, FILE *istream)
{
	if (!phdr || !istream || fread(phdr, sizeof(*phdr), 1, istream) != 1)
		return (1);
	phdr64letoh(phdr);
	return (0);
}

