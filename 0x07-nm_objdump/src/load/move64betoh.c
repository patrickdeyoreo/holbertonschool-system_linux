#include "../load.h"

/**
 * move64beload - load a 64-bit big-endian move records
 *
 * @filename: name of the input file
 * @move: pointer to a 64-bit big-endian move records
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int move64beload(const char *filename, Elf64_Move *move)
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
	move64betoh(move);
	return (0);
}

