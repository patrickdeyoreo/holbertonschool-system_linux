#include "../etoh.h"

/**
 * phdr32betoh - convert 32-bit big-endian program header to host byte order
 *
 * @phdr: pointer to 32-bit big-endian program header
 */
void phdr32betoh(Elf32_Phdr *phdr)
{
	if (phdr)
	{
		phdr->p_type = be32toh(phdr->p_type);
		phdr->p_offset = be32toh(phdr->p_offset);
		phdr->p_vaddr = be32toh(phdr->p_vaddr);
		phdr->p_paddr = be32toh(phdr->p_paddr);
		phdr->p_filesz = be32toh(phdr->p_filesz);
		phdr->p_memsz = be32toh(phdr->p_memsz);
		phdr->p_flags = be32toh(phdr->p_flags);
		phdr->p_align = be32toh(phdr->p_align);
	}
}

