#include "hreadelf.h"

/**
 * elf_osabi - print ELF OS/ABI
 *
 * @e_ident: ELF header identifier bits
 */
void elf_osabi(unsigned char (*e_ident)[EI_NIDENT])
{
	const char *os_table[] = {
		"UNIX - System V",
		"UNIX - HP-UX",
		"UNIX - NetBSD",
		"UNIX - GNU",
		"<unknown: 4>",
		"<unknown: 5>",
		"UNIX - Solaris",
		"UNIX - AIX",
		"UNIX - IRIX",
		"UNIX - FreeBSD",
		"UNIX - Tru64",
		"Novell - Modesto",
		"UNIX - OpenBSD",
		"VMS - OpenVMS",
		"HP - Non-Stop Kernel",
		"AROS",
		"FenixOS",
		"Nuxi CloudABI",
		"Stratus Technologies OpenVOS"
	};

	printf("  %-34s ", "OS/ABI:");

	if ((*e_ident)[EI_OSABI] < sizeof(os_table) / sizeof(*os_table))
		printf("%s\n", os_table[(*e_ident)[EI_OSABI]]);
	else
		printf("<unknown: %x>\n", (*e_ident)[EI_OSABI]);
}
