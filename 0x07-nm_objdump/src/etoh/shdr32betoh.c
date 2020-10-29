#include "../etoh.h"

/**
 * shdr32betoh - convert 32-bit big-endian section header to host byte order
 *
 * @shdr: pointer to 32-bit big-endian ELF section header
 */
void shdr32betoh(Elf32_Shdr *shdr)
{
	if (shdr)
	{
		shdr->sh_name = be32toh(shdr->sh_name);
		shdr->sh_type = be32toh(shdr->sh_type);
		shdr->sh_flags = be32toh(shdr->sh_flags);
		shdr->sh_addr = be32toh(shdr->sh_addr);
		shdr->sh_offset = be32toh(shdr->sh_offset);
		shdr->sh_size = be32toh(shdr->sh_size);
		shdr->sh_link = be32toh(shdr->sh_link);
		shdr->sh_info = be32toh(shdr->sh_info);
		shdr->sh_addralign = be32toh(shdr->sh_addralign);
		shdr->sh_entsize = be32toh(shdr->sh_entsize);
	}
}
