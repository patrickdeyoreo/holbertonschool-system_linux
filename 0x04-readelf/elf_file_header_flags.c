#include "hreadelf.h"

/**
 * elf_flags - print ELF flags
 *
 * @e_flags: ELF flags
 */
void elf_flags(Elf64_Word e_flags)
{
	printf("  %-34s 0x%x\n", "Flags:", e_flags);
}
