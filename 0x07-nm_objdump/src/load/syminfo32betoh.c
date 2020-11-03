#include "../load.h"

/**
 * syminfo32beload - load a 32-bit big-endian dyn sym info
 *
 * @filename: name of the input file
 * @syminfo: pointer to a 32-bit big-endian dyn sym info
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int syminfo32beload(const char *filename, Elf32_Syminfo *syminfo)
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
	syminfo32betoh(syminfo);
	return (0);
}

