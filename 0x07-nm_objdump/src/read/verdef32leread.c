#include "../read.h"

/**
 * verdef32leread - read a 32-bit little-endian version defs
 *
 * @verdef: pointer to a 32-bit little-endian version defs
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int verdef32leread(Elf32_Verdef *verdef, FILE *istream)
{
	if (!verdef || !istream || fread(verdef, sizeof(*verdef), 1, istream) != 1)
		return (1);
	verdef32letoh(verdef);
	return (0);
}

