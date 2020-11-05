#include "../read.h"

/**
 * move64beread - read a 64-bit big-endian move records
 *
 * @move: pointer to a 64-bit big-endian move records
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int move64beread(Elf64_Move *move, FILE *istream)
{
	if (!move || !istream || fread(move, sizeof(*move), 1, istream) != 1)
		return (1);
	move64betoh(move);
	return (0);
}

