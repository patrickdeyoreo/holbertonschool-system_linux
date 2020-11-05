#include "../read.h"

/**
 * syminfo64beread - read a 64-bit big-endian dyn sym info
 *
 * @syminfo: pointer to a 64-bit big-endian dyn sym info
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int syminfo64beread(Elf64_Syminfo *syminfo, FILE *istream)
{
	if (!syminfo || !istream || fread(syminfo, sizeof(*syminfo), 1, istream) != 1)
		return (1);
	syminfo64betoh(syminfo);
	return (0);
}

