#include <string.h>

#include "hnm.h"

/**
 * hnm32 - list symbols from 32-bit object files
 *
 * @filename: name of the input file
 * @ident: elf identifier bytes
 *
 * Return: 1 if an error occurs, otherwise 0
 */
static int hnm32(const char *filename, unsigned char (*ident)[EI_NIDENT])
{
	loadfn_t loadfntab[LOADFNTABSIZE] = {0};
	Elf32_Ehdr ehdr;

	switch ((*ident)[EI_DATA])
	{
	case ELFDATA2LSB:
		loadfntabinit32le(&loadfntab);
		break;
	case ELFDATA2MSB:
		loadfntabinit32be(&loadfntab);
		break;
	default:
		return (1);
	}
	if (loadfntab[ehdrloadfntabidx](filename, &ehdr) != 0)
	{
		return (1);
	}
	return (0);
}

/**
 * hnm64 - list symbols from 64-bit object files
 *
 * @filename: name of the input file
 * @ident: elf identifier bytes
 *
 * Return: 1 if an error occurs, otherwise 0
 */
static int hnm64(const char *filename, unsigned char (*ident)[EI_NIDENT])
{
	loadfn_t loadfntab[LOADFNTABSIZE] = {0};
	Elf64_Ehdr ehdr;

	switch ((*ident)[EI_DATA])
	{
	case ELFDATA2LSB:
		loadfntabinit64le(&loadfntab);
		break;
	case ELFDATA2MSB:
		loadfntabinit64be(&loadfntab);
		break;
	default:
		return (1);
	}
	if (loadfntab[ehdrloadfntabidx](filename, &ehdr) != 0)
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
	FILE *istream = filename ? fopen(filename, "r") : NULL;

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
		return (hnm32(filename, &ident));
	case ELFCLASS64:
		return (hnm64(filename, &ident));
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
 * Return: non-zero if an error occurs, otherwise 0
 */
int main(int argc, char **argv)
{
	int status = argc > 1 ? 0 : hnm("a.out");

	while (*++argv)
		status += hnm(*argv);

	return (status);
}
