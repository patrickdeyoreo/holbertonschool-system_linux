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
	int (*load)(const char *, Elf32_Ehdr *) = NULL;
	Elf32_Ehdr ehdr;

	switch ((*ident)[EI_DATA])
	{
	case ELFDATA2LSB:
		load = ehdr32leload;
		break;
	case ELFDATA2MSB:
		load = ehdr32beload;
		break;
	default:
		return (1);
	}
	if (load(filename, &ehdr) == 1)
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
	int (*load)(const char *, Elf64_Ehdr *) = NULL;
	Elf64_Ehdr ehdr;

	switch ((*ident)[EI_DATA])
	{
	case ELFDATA2LSB:
		load = ehdr64leload;
		break;
	case ELFDATA2MSB:
		load = ehdr64beload;
		break;
	default:
		return (1);
	}
	if (load(filename, &ehdr) == 1)
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
	int (*hnmxx)(const char *, unsigned char (*)[EI_NIDENT]) = NULL;
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
		hnmxx = hnm32;
		break;
	case ELFCLASS64:
		hnmxx = hnm64;
		break;
	default:
		return (1);
	}
	return (hnmxx(filename, &ident));
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
