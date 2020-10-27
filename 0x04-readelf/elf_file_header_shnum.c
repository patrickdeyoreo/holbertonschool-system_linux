#include "hreadelf.h"

/**
 * elf_shnum - print ELF section header entry count
 *
 * @e_shnum: ELF section header entry count
 */
void elf_shnum(Elf64_Half e_shnum)
{
	printf("  %-34s %u\n", "Number of section headers:", e_shnum);
}
