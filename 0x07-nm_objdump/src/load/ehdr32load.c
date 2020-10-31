#include "../load.h"

/**
 * ehdr32load - handle a 32-bit elf header
 *
 * @filename: name of the input file
 * @ehdr: pointer to a 32-bit ehdr structure in which to write
 *
 * Return: 1 if an error occurs, otherwise 0
 */
int ehdr32load(const char *filename, Elf32_Ehdr *ehdr)
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
		ehdr32letoh(ehdr);
		break;
	case ELFDATA2MSB:
		ehdr32betoh(ehdr);
		break;
	default:
		return (1);
	}
	return (0);
}
