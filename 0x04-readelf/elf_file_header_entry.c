#include "hreadelf.h"

/**
 * elf_entry - print entry point address
 * @e_entry: entry point address
 */
void elf_entry(Elf64_Addr e_entry)
{
	printf("  %-34s 0x%lx\n", "Entry point address:", e_entry);
}
