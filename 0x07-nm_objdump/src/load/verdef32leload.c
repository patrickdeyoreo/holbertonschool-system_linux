#include "../load.h"

/**
 * verdef32leload - load a 32-bit little-endian version defs
 *
 * @filename: name of the input file
 * @verdef: pointer to a 32-bit little-endian version defs
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int verdef32leload(const char *filename, Elf32_Verdef *verdef)
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
	verdef32letoh(verdef);
	return (0);
}

