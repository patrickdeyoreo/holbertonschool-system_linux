#include "hreadelf.h"

/**
 * elf_ehsize - print ELF header size
 *
 * @e_ehsize: ELF header size
 */
void elf_ehsize(Elf64_Half e_ehsize)
{
	printf("  %-34s %u (bytes)\n", "Size of this header:", e_ehsize);
}
