#include "../etoh.h"

/**
 * rela64letoh - convert 64-bit little-endian reloc + addend to host byte order
 *
 * @rela: pointer to 64-bit little-endian reloc with addend
 */
void rela64letoh(Elf64_Rela *rela)
{
	if (rela)
	{
		rela->r_offset = le64toh(rela->r_offset);
		rela->r_info = le64toh(rela->r_info);
		rela->r_addend = le64toh(rela->r_addend);
	}
}

