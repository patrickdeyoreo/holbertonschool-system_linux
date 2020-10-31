#include "../etoh.h"

/**
 * rela64betoh - convert 64-bit big-endian reloc with addend to host byte order
 *
 * @rela: pointer to 64-bit big-endian reloc with addend
 */
void rela64betoh(Elf64_Rela *rela)
{
	if (rela)
	{
		rela->r_offset = be64toh(rela->r_offset);
		rela->r_info = be64toh(rela->r_info);
		rela->r_addend = be64toh(rela->r_addend);
	}
}

