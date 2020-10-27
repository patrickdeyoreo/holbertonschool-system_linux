#include "hreadelf.h"

/**
 * elf_version - print ELF identifier version
 *
 * @e_version: ELF header identifier bits
 */
void elf_version(Elf64_Word e_version)
{
	printf("  %-34s 0x%x\n", "Version:", e_version);
}
