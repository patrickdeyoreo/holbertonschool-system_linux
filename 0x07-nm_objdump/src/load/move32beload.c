#include "../load.h"

/**
 * move32beload - load a 32-bit big-endian move records
 *
 * @filename: name of the input file
 * @move: pointer to a 32-bit big-endian move records
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int move32beload(const char *filename, Elf32_Move *move)
{
	FILE *istream = filename && move ? fopen(filename, "r") : NULL;

	if (!istream)
	{
		return (1);
	}
	if (fread(move, sizeof(*move), 1, istream) != 1)
	{
		fclose(istream);
		return (1);
	}
	fclose(istream);
	move32betoh(move);
	return (0);
}

