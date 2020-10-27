#include "hreadelf.h"

/**
 * elf_ev - print ELF identifier version
 *
 * @e_ident: ELF header identifier bits
 */
void elf_ev(unsigned char (*e_ident)[EI_NIDENT])
{
	printf("  %-34s %u", "Version:", (*e_ident)[EI_VERSION]);

	if ((*e_ident)[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}
