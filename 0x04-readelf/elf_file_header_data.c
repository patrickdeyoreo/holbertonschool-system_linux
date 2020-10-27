#include "hreadelf.h"

/**
 * elf_data - print ELF data
 *
 * @e_ident: ELF header identifier bits
 */
void elf_data(unsigned char (*e_ident)[EI_NIDENT])
{
	printf("  %-34s ", "Data:");

	switch ((*e_ident)[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case  ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("Invalid data encoding\n");
		break;
	}
}
