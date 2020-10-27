#include "hreadelf.h"

/**
 * elf_shentsize - print ELF section header table entry size
 *
 * @e_shentsize: ELF section header table entry size
 */
void elf_shentsize(Elf64_Half e_shentsize)
{
	printf("  %-34s %u (bytes)\n", "Size of section headers:", e_shentsize);
}
