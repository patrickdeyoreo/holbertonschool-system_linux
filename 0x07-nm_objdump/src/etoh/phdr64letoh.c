#include "../etoh.h"

/**
 * phdr64letoh - convert 64-bit little-endian program header to host byte order
 *
 * @phdr: pointer to 64-bit little-endian program header
 */
void phdr64letoh(Elf64_Phdr *phdr)
{
	if (phdr)
	{
		phdr->p_type = le32toh(phdr->p_type);
		phdr->p_flags = le32toh(phdr->p_flags);
		phdr->p_offset = le64toh(phdr->p_offset);
		phdr->p_vaddr = le64toh(phdr->p_vaddr);
		phdr->p_paddr = le64toh(phdr->p_paddr);
		phdr->p_filesz = le64toh(phdr->p_filesz);
		phdr->p_memsz = le64toh(phdr->p_memsz);
		phdr->p_align = le64toh(phdr->p_align);
	}
}

