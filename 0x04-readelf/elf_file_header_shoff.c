#include "hreadelf.h"

/**
 * elf_shoff - print ELF section header offset
 *
 * @e_shoff: ELF section header offset
 */
void elf_shoff(Elf64_Off e_shoff)
{
	printf("  %-34s %lu (bytes into file)\n", "Start of section headers:",
		e_shoff);
}
