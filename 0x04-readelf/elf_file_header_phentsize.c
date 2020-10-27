#include "hreadelf.h"

/**
 * elf_phentsize - print ELF program header table entry size
 *
 * @e_phentsize: ELF program header table entry size
 */
void elf_phentsize(Elf64_Half e_phentsize)
{
	printf("  %-34s %u (bytes)\n", "Size of program headers:", e_phentsize);
}
