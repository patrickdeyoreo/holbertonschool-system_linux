#include "hreadelf.h"

/**
 * elf_phoff - print ELF program header offset
 *
 * @e_phoff: ELF program header offset
 */
void elf_phoff(Elf64_Off e_phoff)
{
	printf("  %-34s %lu (bytes into file)\n", "Start of program headers:",
		e_phoff);
}
