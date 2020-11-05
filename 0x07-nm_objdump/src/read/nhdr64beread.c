#include "../read.h"

/**
 * nhdr64beread - read a 64-bit big-endian note header
 *
 * @nhdr: pointer to a 64-bit big-endian note header
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int nhdr64beread(Elf64_Nhdr *nhdr, FILE *istream)
{
	if (!nhdr || !istream || fread(nhdr, sizeof(*nhdr), 1, istream) != 1)
		return (1);
	nhdr64betoh(nhdr);
	return (0);
}

