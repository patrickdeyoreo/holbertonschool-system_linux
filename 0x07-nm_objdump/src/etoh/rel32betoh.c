#include "../etoh.h"

/**
 * rel32betoh - convert 32-bit big-endian reloc tab entry to host byte order
 *
 * @rel: pointer to 32-bit big-endian reloc tab entry
 */
void rel32betoh(Elf32_Rel *rel)
{
	if (rel)
	{
		rel->r_offset = be32toh(rel->r_offset);
		rel->r_info = be32toh(rel->r_info);
	}
}

