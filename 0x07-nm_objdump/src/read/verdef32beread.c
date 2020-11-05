#include "../read.h"

/**
 * verdef32beread - read a 32-bit big-endian version defs
 *
 * @verdef: pointer to a 32-bit big-endian version defs
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int verdef32beread(Elf32_Verdef *verdef, FILE *istream)
{
	if (!verdef || !istream || fread(verdef, sizeof(*verdef), 1, istream) != 1)
		return (1);
	verdef32betoh(verdef);
	return (0);
}

