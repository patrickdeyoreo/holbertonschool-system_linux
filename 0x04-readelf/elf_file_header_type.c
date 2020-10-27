#include "hreadelf.h"

/**
 * elf_type - print ELF type
 *
 * @e_type: the ELF type
 */
void elf_type(Elf64_Half e_type)
{
	const char *type_table[ET_NUM] = {
		"NONE (No file type)",
		"REL (Relocatable file)",
		"EXEC (Executable file)",
		"DYN (Shared object file)",
		"CORE (Core file)"
	};

	printf("  %-34s ", "Type:");

	if (e_type < ET_NUM)
		printf("%s\n", type_table[e_type]);
	else if (e_type >= ET_LOOS && e_type <= ET_HIOS)
		printf("OS Specific: (%4x)\n", e_type);
	else if (e_type >= ET_LOPROC)
		printf("Processor Specific: (%4x)\n", e_type);
	else
		printf("<unknown: %x>\n", e_type);
}
