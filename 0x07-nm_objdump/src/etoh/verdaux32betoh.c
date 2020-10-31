#include "../etoh.h"

/**
 * verdaux32betoh - convert 32-bit big-endian ver info to host byte order
 *
 * @verdaux: pointer to 32-bit big-endian ver info
 */
void verdaux32betoh(Elf32_Verdaux *verdaux)
{
	if (verdaux)
	{
		verdaux->vda_name = be32toh(verdaux->vda_name);
		verdaux->vda_next = be32toh(verdaux->vda_next);
	}
}

