#include "../etoh.h"

/**
 * shdr32letoh - convert 32-bit little-endian section header to host byte order
 *
 * @shdr: pointer to 32-bit little-endian ELF section header
 */
void shdr32letoh(Elf32_Shdr *shdr)
{
	if (shdr)
	{
		shdr->sh_name = le32toh(shdr->sh_name);
		shdr->sh_type = le32toh(shdr->sh_type);
		shdr->sh_flags = le32toh(shdr->sh_flags);
		shdr->sh_addr = le32toh(shdr->sh_addr);
		shdr->sh_offset = le32toh(shdr->sh_offset);
		shdr->sh_size = le32toh(shdr->sh_size);
		shdr->sh_link = le32toh(shdr->sh_link);
		shdr->sh_info = le32toh(shdr->sh_info);
		shdr->sh_addralign = le32toh(shdr->sh_addralign);
		shdr->sh_entsize = le32toh(shdr->sh_entsize);
	}
}
