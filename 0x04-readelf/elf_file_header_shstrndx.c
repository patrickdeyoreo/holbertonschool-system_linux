#include "hreadelf.h"

/**
 * elf_shstrndx - print ELF section header string table index
 *
 * @e_shstrndx: ELF section header string table index
 */
void elf_shstrndx(Elf64_Half e_shstrndx)
{
	printf("  %-34s %u\n", "Section header string table index:", e_shstrndx);
}
