#include "../etoh.h"

/**
 * rela32letoh - convert 32-bit little-endian reloc + addend to host byte order
 *
 * @rela: pointer to 32-bit little-endian reloc with addend
 */
void rela32letoh(Elf32_Rela *rela)
{
	if (rela)
	{
		rela->r_offset = le32toh(rela->r_offset);
		rela->r_info = le32toh(rela->r_info);
		rela->r_addend = le32toh(rela->r_addend);
	}
}

