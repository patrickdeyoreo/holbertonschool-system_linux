#include "../load.h"

/**
 * ehdr64load - handle a 64-bit ELF header
 *
 * @filename: name of the input file
 * @ehdr: pointer to a 64-bit ehdr structure in which to write
 *
 * Return: 1 if an error occurs, otherwise 0
 */
int ehdr64load(const char *filename, Elf64_Ehdr *ehdr)
{
	FILE *istream = fopen(filename, "r");

	if (!istream)
	{
		return (1);
	}
	if (fread(ehdr, sizeof(*ehdr), 1, istream) != 1)
	{
		fclose(istream);
		return (1);
	}
	fclose(istream);
	switch (ehdr->e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		ehdr64letoh(ehdr);
		break;
	case ELFDATA2MSB:
		ehdr64betoh(ehdr);
		break;
	default:
		return (1);
	}
	return (0);
}
