#include "../read.h"

/**
 * move32beread - read a 32-bit big-endian move records
 *
 * @move: pointer to a 32-bit big-endian move records
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int move32beread(Elf32_Move *move, FILE *istream)
{
	if (!move || !istream || fread(move, sizeof(*move), 1, istream) != 1)
		return (1);
	move32betoh(move);
	return (0);
}

