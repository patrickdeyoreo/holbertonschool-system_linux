#include "hreadelf.h"

/**
 * elf_ident - print ELF identifier data
 *
 * @e_ident: ELF header identifier bits
 */
void elf_ident(unsigned char (*e_ident)[EI_NIDENT])
{
	elf_magic(e_ident);
	elf_class(e_ident);
	elf_data(e_ident);
	elf_ev(e_ident);
	elf_osabi(e_ident);
	elf_abivers(e_ident);
}
