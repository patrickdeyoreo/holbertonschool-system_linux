#include "../read.h"

/**
 * syminfo32leread - read a 32-bit little-endian dyn sym info
 *
 * @syminfo: pointer to a 32-bit little-endian dyn sym info
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int syminfo32leread(Elf32_Syminfo *syminfo, FILE *istream)
{
	if (!syminfo || !istream || fread(syminfo, sizeof(*syminfo), 1, istream) != 1)
		return (1);
	syminfo32letoh(syminfo);
	return (0);
}

