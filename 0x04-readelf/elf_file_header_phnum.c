#include "hreadelf.h"

/**
 * elf_phnum - print ELF program header entry count
 *
 * @e_phnum: ELF program header entry count
 */
void elf_phnum(Elf64_Half e_phnum)
{
	printf("  %-34s %u\n", "Number of program headers:", e_phnum);
}
