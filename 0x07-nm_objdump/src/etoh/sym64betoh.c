#include "../etoh.h"

/**
 * sym64betoh - convert 64-bit big-endian sym table entry to host byte order
 *
 * @sym: pointer to 64-bit big-endian sym table entry
 */
void sym64betoh(Elf64_Sym *sym)
{
	if (sym)
	{
		sym->st_name = be32toh(sym->st_name);
		sym->st_shndx = be16toh(sym->st_shndx);
		sym->st_value = be64toh(sym->st_value);
		sym->st_size = be64toh(sym->st_size);
	}
}

