#include "../etoh.h"

/**
 * sym32betoh - convert 32-bit big-endian sym table entry to host byte order
 *
 * @sym: pointer to 32-bit big-endian sym table entry
 */
void sym32betoh(Elf32_Sym *sym)
{
	if (sym)
	{
		sym->st_name = be32toh(sym->st_name);
		sym->st_value = be32toh(sym->st_value);
		sym->st_size = be32toh(sym->st_size);
		sym->st_shndx = be16toh(sym->st_shndx);
	}
}

