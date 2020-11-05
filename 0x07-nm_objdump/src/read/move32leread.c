#include "../read.h"

/**
 * move32leread - read a 32-bit little-endian move records
 *
 * @move: pointer to a 32-bit little-endian move records
 * @istream: input file stream
 *
 * Return: Upon error, return 1. Otherwise, return 0.
 */
int move32leread(Elf32_Move *move, FILE *istream)
{
	if (!move || !istream || fread(move, sizeof(*move), 1, istream) != 1)
		return (1);
	move32letoh(move);
	return (0);
}

