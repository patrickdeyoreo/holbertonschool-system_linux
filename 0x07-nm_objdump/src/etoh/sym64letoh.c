#include "../etoh.h"

/**
 * sym64letoh - convert 64-bit little-endian sym table entry to host byte order
 *
 * @sym: pointer to 64-bit little-endian sym table entry
 */
void sym64letoh(Elf64_Sym *sym)
{
	if (sym)
	{
		sym->st_name = le32toh(sym->st_name);
		sym->st_shndx = le16toh(sym->st_shndx);
		sym->st_value = le64toh(sym->st_value);
		sym->st_size = le64toh(sym->st_size);
	}
}

