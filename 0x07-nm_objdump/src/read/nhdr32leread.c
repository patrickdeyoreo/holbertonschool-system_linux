#include "../read.h"

/**
 * nhdr32leread - read a 32-bit little-endian note header
 *
 * @nhdr: pointer to a 32-bit little-endian note header
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int nhdr32leread(Elf32_Nhdr *nhdr, FILE *istream)
{
	if (!nhdr || !istream || fread(nhdr, sizeof(*nhdr), 1, istream) != 1)
		return (1);
	nhdr32letoh(nhdr);
	return (0);
}

