#include "../etoh.h"

/**
 * verdaux32letoh - convert 32-bit little-endian ver info to host byte order
 *
 * @verdaux: pointer to 32-bit little-endian ver info
 */
void verdaux32letoh(Elf32_Verdaux *verdaux)
{
	if (verdaux)
	{
		verdaux->vda_name = le32toh(verdaux->vda_name);
		verdaux->vda_next = le32toh(verdaux->vda_next);
	}
}

