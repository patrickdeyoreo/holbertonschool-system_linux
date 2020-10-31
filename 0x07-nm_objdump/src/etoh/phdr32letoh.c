#include "../etoh.h"

/**
 * phdr32letoh - convert 32-bit little-endian program header to host byte order
 *
 * @phdr: pointer to 32-bit little-endian program header
 */
void phdr32letoh(Elf32_Phdr *phdr)
{
	if (phdr)
	{
		phdr->p_type = le32toh(phdr->p_type);
		phdr->p_offset = le32toh(phdr->p_offset);
		phdr->p_vaddr = le32toh(phdr->p_vaddr);
		phdr->p_paddr = le32toh(phdr->p_paddr);
		phdr->p_filesz = le32toh(phdr->p_filesz);
		phdr->p_memsz = le32toh(phdr->p_memsz);
		phdr->p_flags = le32toh(phdr->p_flags);
		phdr->p_align = le32toh(phdr->p_align);
	}
}

