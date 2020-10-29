#include "../etoh.h"

/**
 * shdr64letoh - convert 64-bit little-endian section header to host byte order
 *
 * @shdr: pointer to 64-bit little-endian ELF section header
 */
void shdr64letoh(Elf64_Shdr *shdr)
{
	if (shdr)
	{
		shdr->sh_name = le32toh(shdr->sh_name);
		shdr->sh_type = le32toh(shdr->sh_type);
		shdr->sh_flags = le64toh(shdr->sh_flags);
		shdr->sh_addr = le64toh(shdr->sh_addr);
		shdr->sh_offset = le64toh(shdr->sh_offset);
		shdr->sh_size = le64toh(shdr->sh_size);
		shdr->sh_link = le32toh(shdr->sh_link);
		shdr->sh_info = le32toh(shdr->sh_info);
		shdr->sh_addralign = le64toh(shdr->sh_addralign);
		shdr->sh_entsize = le64toh(shdr->sh_entsize);
	}
}
