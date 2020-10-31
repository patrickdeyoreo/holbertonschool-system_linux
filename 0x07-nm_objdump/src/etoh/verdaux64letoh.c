#include "../etoh.h"

/**
 * verdaux64letoh - convert 64-bit little-endian ver info to host byte order
 *
 * @verdaux: pointer to 64-bit little-endian ver info
 */
void verdaux64letoh(Elf64_Verdaux *verdaux)
{
	if (verdaux)
	{
		verdaux->vda_name = le32toh(verdaux->vda_name);
		verdaux->vda_next = le32toh(verdaux->vda_next);
	}
}

