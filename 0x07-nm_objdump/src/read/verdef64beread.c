#include "../read.h"

/**
 * verdef64beread - read a 64-bit big-endian version defs
 *
 * @verdef: pointer to a 64-bit big-endian version defs
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int verdef64beread(Elf64_Verdef *verdef, FILE *istream)
{
	if (!verdef || !istream || fread(verdef, sizeof(*verdef), 1, istream) != 1)
		return (1);
	verdef64betoh(verdef);
	return (0);
}

