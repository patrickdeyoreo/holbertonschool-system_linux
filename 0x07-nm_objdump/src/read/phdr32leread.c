#include "../read.h"

/**
 * phdr32leread - read a 32-bit little-endian program header
 *
 * @phdr: pointer to a 32-bit little-endian program header
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int phdr32leread(Elf32_Phdr *phdr, FILE *istream)
{
	if (!phdr || !istream || fread(phdr, sizeof(*phdr), 1, istream) != 1)
		return (1);
	phdr32letoh(phdr);
	return (0);
}

