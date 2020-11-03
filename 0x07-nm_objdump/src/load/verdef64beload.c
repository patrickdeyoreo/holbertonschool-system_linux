#include "../load.h"

/**
 * verdef64beload - load a 64-bit big-endian version defs
 *
 * @filename: name of the input file
 * @verdef: pointer to a 64-bit big-endian version defs
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int verdef64beload(const char *filename, Elf64_Verdef *verdef)
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
	verdef64betoh(verdef);
	return (0);
}

