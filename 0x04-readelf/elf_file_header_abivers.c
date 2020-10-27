#include "hreadelf.h"

/**
 * elf_abivers - print ELF ABI version
 *
 * @e_ident: ELF header identifier bits
 */
void elf_abivers(unsigned char (*e_ident)[EI_NIDENT])
{
	printf("  %-34s %u\n", "ABI Version:", (*e_ident)[EI_ABIVERSION]);
}
