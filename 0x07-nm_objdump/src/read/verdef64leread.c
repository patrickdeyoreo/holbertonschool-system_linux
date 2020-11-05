#include "../read.h"

/**
 * verdef64leread - read a 64-bit little-endian version defs
 *
 * @verdef: pointer to a 64-bit little-endian version defs
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int verdef64leread(Elf64_Verdef *verdef, FILE *istream)
{
	if (!verdef || !istream || fread(verdef, sizeof(*verdef), 1, istream) != 1)
		return (1);
	verdef64letoh(verdef);
	return (0);
}

