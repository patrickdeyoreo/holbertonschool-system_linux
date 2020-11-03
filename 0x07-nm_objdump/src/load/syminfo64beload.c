#include "../load.h"

/**
 * syminfo64beload - load a 64-bit big-endian dyn sym info
 *
 * @filename: name of the input file
 * @syminfo: pointer to a 64-bit big-endian dyn sym info
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int syminfo64beload(const char *filename, Elf64_Syminfo *syminfo)
{
	FILE *istream = filename && syminfo ? fopen(filename, "r") : NULL;

	if (!istream)
	{
		return (1);
	}
	if (fread(syminfo, sizeof(*syminfo), 1, istream) != 1)
	{
		fclose(istream);
		return (1);
	}
	fclose(istream);
	syminfo64betoh(syminfo);
	return (0);
}

