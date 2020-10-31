#include "../etoh.h"

/**
 * rel64betoh - convert 64-bit big-endian reloc tab entry to host byte order
 *
 * @rel: pointer to 64-bit big-endian reloc tab entry
 */
void rel64betoh(Elf64_Rel *rel)
{
	if (rel)
	{
		rel->r_offset = be64toh(rel->r_offset);
		rel->r_info = be64toh(rel->r_info);
	}
}

