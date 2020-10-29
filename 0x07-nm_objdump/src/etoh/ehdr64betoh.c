#include "../etoh.h"

/**
 * ehdr64betoh - convert 64-bit big-endian ELF header to host byte order
 *
 * @ehdr: pointer to 64-bit big-endian elf header
 */
void ehdr64betoh(Elf64_Ehdr *ehdr)
{
	if (ehdr)
	{
		ehdr->e_type = be16toh(ehdr->e_type);
		ehdr->e_machine = be16toh(ehdr->e_machine);
		ehdr->e_version = be32toh(ehdr->e_version);
		ehdr->e_entry = be64toh(ehdr->e_entry);
		ehdr->e_phoff = be64toh(ehdr->e_phoff);
		ehdr->e_shoff = be64toh(ehdr->e_shoff);
		ehdr->e_flags = be32toh(ehdr->e_flags);
		ehdr->e_ehsize = be16toh(ehdr->e_ehsize);
		ehdr->e_phentsize = be16toh(ehdr->e_phentsize);
		ehdr->e_phnum = be16toh(ehdr->e_phnum);
		ehdr->e_shentsize = be16toh(ehdr->e_shentsize);
		ehdr->e_shnum = be16toh(ehdr->e_shnum);
		ehdr->e_shstrndx = be16toh(ehdr->e_shstrndx);
	}
}
