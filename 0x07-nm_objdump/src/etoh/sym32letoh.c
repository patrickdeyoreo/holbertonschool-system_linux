#include "../etoh.h"

/**
 * sym32letoh - convert 32-bit little-endian sym table entry to host byte order
 *
 * @sym: pointer to 32-bit little-endian sym table entry
 */
void sym32letoh(Elf32_Sym *sym)
{
	if (sym)
	{
		sym->st_name = le32toh(sym->st_name);
		sym->st_value = le32toh(sym->st_value);
		sym->st_size = le32toh(sym->st_size);
		sym->st_shndx = le16toh(sym->st_shndx);
	}
}

