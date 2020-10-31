#include <string.h>

#include "hnm.h"

/**
 * hnm32 - list symbols from 32-bit object files
 *
 * @filename: name of the input file
 *
 * Return: 1 if an error occurs, otherwise 0
 */
int hnm32(const char *filename)
{
	Elf32_Ehdr ehdr;

	if (ehdr32load(filename, &ehdr) == 1)
	{
		return (1);
	}
	return (0);
}

/**
 * hnm64 - list symbols from 64-bit object files
 *
 * @filename: name of the input file
 *
 * Return: 1 if an error occurs, otherwise 0
 */
int hnm64(const char *filename)
{
	Elf64_Ehdr ehdr;

	if (ehdr64load(filename, &ehdr) == 1)
	{
		return (1);
	}
	return (0);
}

/**
 * hnm - list symbols from object files
 *
 * @filename: name of the input file
 *
 * Return: 1 if an error occurs, otherwise 0
 */
int hnm(const char *filename)
{
	unsigned char ident[EI_NIDENT] = {0};
	FILE *istream = fopen(filename, "r");

	if (!istream)
	{
		return (1);
	}
	if (fread(ident, 1, EI_NIDENT, istream) != EI_NIDENT)
	{
		fclose(istream);
		return (1);
	}
	fclose(istream);
	if (memcmp(ident, ELFMAG, SELFMAG))
	{
		return (1);
	}
	switch (ident[EI_CLASS])
	{
	case ELFCLASS32:
		return (hnm32(filename));
	case ELFCLASS64:
		return (hnm64(filename));
	default:
		return (1);
	}
}

/**
 * main - entry point
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: always 1
 */
int main(int argc, char **argv)
{
	int status = argc > 1 ? 0 : hnm("a.out");

	while (*++argv)
		status += hnm(*argv);

	return (status);
}
