#include "../etoh.h"

/**
 * phdr64betoh - convert 64-bit big-endian program header to host byte order
 *
 * @phdr: pointer to 64-bit big-endian program header
 */
void phdr64betoh(Elf64_Phdr *phdr)
{
	if (phdr)
	{
		phdr->p_type = be32toh(phdr->p_type);
		phdr->p_flags = be32toh(phdr->p_flags);
		phdr->p_offset = be64toh(phdr->p_offset);
		phdr->p_vaddr = be64toh(phdr->p_vaddr);
		phdr->p_paddr = be64toh(phdr->p_paddr);
		phdr->p_filesz = be64toh(phdr->p_filesz);
		phdr->p_memsz = be64toh(phdr->p_memsz);
		phdr->p_align = be64toh(phdr->p_align);
	}
}

