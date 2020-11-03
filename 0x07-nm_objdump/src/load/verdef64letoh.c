#include "../load.h"

/**
 * verdef64leload - load a 64-bit little-endian version defs
 *
 * @filename: name of the input file
 * @verdef: pointer to a 64-bit little-endian version defs
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int verdef64leload(const char *filename, Elf64_Verdef *verdef)
{
	FILE *istream = filename && verdef ? fopen(filename, "r") : NULL;

	if (!istream)
	{
		return (1);
	}
	if (fread(verdef, sizeof(*verdef), 1, istream) != 1)
	{
		fclose(istream);
		return (1);
	}
	fclose(istream);
	verdef64letoh(verdef);
	return (0);
}

