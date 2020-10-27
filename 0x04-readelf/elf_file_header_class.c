#include "hreadelf.h"

/**
 * elf_class - print ELF class
 *
 * @e_ident: ELF header identifier bits
 */
void elf_class(unsigned char (*e_ident)[EI_NIDENT])
{
	printf("  %-34s ", "Class:");

	switch ((*e_ident)[EI_CLASS])
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", (*e_ident)[EI_CLASS]);
		break;
	}
}
