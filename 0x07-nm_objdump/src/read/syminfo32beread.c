#include "../read.h"

/**
 * syminfo32beread - read a 32-bit big-endian dyn sym info
 *
 * @syminfo: pointer to a 32-bit big-endian dyn sym info
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int syminfo32beread(Elf32_Syminfo *syminfo, FILE *istream)
{
	if (!syminfo || !istream || fread(syminfo, sizeof(*syminfo), 1, istream) != 1)
		return (1);
	syminfo32betoh(syminfo);
	return (0);
}

