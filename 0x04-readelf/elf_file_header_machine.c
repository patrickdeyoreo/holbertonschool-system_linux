#include "hreadelf.h"

/**
 * elf_machine - print ELF machine type
 *
 * @e_machine: the ELF machine type
 */
void elf_machine(Elf64_Half e_machine)
{
	const char *machine_table[] = E_MACHINE_TABLE;

	printf("  %-34s ", "Machine:");

	if (e_machine < EM_NUM && machine_table[e_machine])
		printf("%s\n", machine_table[e_machine]);
	else if (e_machine < EM_NUM)
		printf("%u (reserved)\n", e_machine);
	else
		printf("<unknown: %x>\n", e_machine);
}
