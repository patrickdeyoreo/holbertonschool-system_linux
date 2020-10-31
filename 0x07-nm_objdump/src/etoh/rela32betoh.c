#include "../etoh.h"

/**
 * rela32betoh - convert 32-bit big-endian reloc with addend to host byte order
 *
 * @rela: pointer to 32-bit big-endian reloc with addend
 */
void rela32betoh(Elf32_Rela *rela)
{
	if (rela)
	{
		rela->r_offset = be32toh(rela->r_offset);
		rela->r_info = be32toh(rela->r_info);
		rela->r_addend = be32toh(rela->r_addend);
	}
}

