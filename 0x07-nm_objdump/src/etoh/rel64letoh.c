#include "../etoh.h"

/**
 * rel64letoh - convert 64-bit little-endian reloc tab entry to host byte order
 *
 * @rel: pointer to 64-bit little-endian reloc tab entry
 */
void rel64letoh(Elf64_Rel *rel)
{
	if (rel)
	{
		rel->r_offset = le64toh(rel->r_offset);
		rel->r_info = le64toh(rel->r_info);
	}
}

