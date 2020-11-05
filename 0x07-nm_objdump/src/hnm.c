#include <string.h>

#include "hnm.h"

/**
 * hnm32 - list symbols from 32-bit object files
 *
 * @ident: elf identifier bytes
 * @istream: input file stream
 *
 * Return: 1 if an error occurs, otherwise 0
 */
static int hnm32(unsigned char (*ident)[EI_NIDENT], FILE *istream)
{
	Elf32_Ehdr ehdr;
	readfn_t readfntab[READFNTABSZ] = {0};

	switch ((*ident)[EI_DATA])
	{
	case ELFDATA2LSB:
		readfntab32leinit(&readfntab);
		break;
	case ELFDATA2MSB:
		readfntab32beinit(&readfntab);
		break;
	default:
		return (1);
	}
	if (readfntab[ehdrreadfnidx](&ehdr, istream) != 0)
	{
		return (1);
	}
	return (0);
}

/**
 * hnm64 - list symbols from 64-bit object files
 *
 * @ident: elf identifier bytes
 * @istream: input file stream
 *
 * Return: 1 if an error occurs, otherwise 0
 */
static int hnm64(unsigned char (*ident)[EI_NIDENT], FILE *istream)
{
	readfn_t readfntab[READFNTABSZ] = {0};
	Elf64_Ehdr ehdr;

	switch ((*ident)[EI_DATA])
	{
	case ELFDATA2LSB:
		readfntab64leinit(&readfntab);
		break;
	case ELFDATA2MSB:
		readfntab64beinit(&readfntab);
		break;
	default:
		return (1);
	}
	if (readfntab[ehdrreadfnidx](&ehdr, istream) != 0)
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
	int (*xx)(unsigned char (*)[EI_NIDENT], FILE *) = NULL;
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
	if (memcmp(ident, ELFMAG, SELFMAG))
	{
		fclose(istream);
		return (1);
	}
	switch (ident[EI_CLASS])
	{
	case ELFCLASS32:
		xx = hnm32;
		break;
	case ELFCLASS64:
		xx = hnm64;
		break;
	default:
		return (1);
	}
	rewind(istream);
	switch (xx(&ident, istream))
	{
	case 0:
		fclose(istream);
		return (0);
	default:
		fclose(istream);
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
