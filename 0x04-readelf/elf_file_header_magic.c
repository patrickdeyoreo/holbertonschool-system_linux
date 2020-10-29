#include "hreadelf.h"

/**
 * elf_magic - print ELF magic
 *
 * @e_ident: ELF header identifier bits
 */
void elf_magic(unsigned char (*e_ident)[EI_NIDENT])
{
	unsigned int i = 0;

	printf("ELF Header:\n  Magic:   ");
	while (i < EI_NIDENT)
		printf("%02x ", (*e_ident)[i++]);
	printf("\n");
}
