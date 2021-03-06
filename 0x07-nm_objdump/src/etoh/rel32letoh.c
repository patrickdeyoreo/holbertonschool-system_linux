#include "../etoh.h"

/**
 * rel32letoh - convert 32-bit little-endian reloc tab entry to host byte order
 *
 * @rel: pointer to 32-bit little-endian reloc tab entry
 */
void rel32letoh(Elf32_Rel *rel)
{
	if (rel)
	{
		rel->r_offset = le32toh(rel->r_offset);
		rel->r_info = le32toh(rel->r_info);
	}
}

