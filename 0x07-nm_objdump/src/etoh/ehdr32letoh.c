#include "../etoh.h"

/**
 * ehdr32letoh - convert 32-bit little-endian ELF header to host byte order
 *
 * @ehdr: pointer to 32-bit little-endian elf header
 */
void ehdr32letoh(Elf32_Ehdr *ehdr)
{
	if (ehdr)
	{
		ehdr->e_type = le16toh(ehdr->e_type);
		ehdr->e_machine = le16toh(ehdr->e_machine);
		ehdr->e_version = le32toh(ehdr->e_version);
		ehdr->e_entry = le32toh(ehdr->e_entry);
		ehdr->e_phoff = le32toh(ehdr->e_phoff);
		ehdr->e_shoff = le32toh(ehdr->e_shoff);
		ehdr->e_flags = le32toh(ehdr->e_flags);
		ehdr->e_ehsize = le16toh(ehdr->e_ehsize);
		ehdr->e_phentsize = le16toh(ehdr->e_phentsize);
		ehdr->e_phnum = le16toh(ehdr->e_phnum);
		ehdr->e_shentsize = le16toh(ehdr->e_shentsize);
		ehdr->e_shnum = le16toh(ehdr->e_shnum);
		ehdr->e_shstrndx = le16toh(ehdr->e_shstrndx);
	}
}
