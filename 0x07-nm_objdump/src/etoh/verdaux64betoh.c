#include "../etoh.h"

/**
 * verdaux64betoh - convert 64-bit big-endian ver info to host byte order
 *
 * @verdaux: pointer to 64-bit big-endian ver info
 */
void verdaux64betoh(Elf64_Verdaux *verdaux)
{
	if (verdaux)
	{
		verdaux->vda_name = be32toh(verdaux->vda_name);
		verdaux->vda_next = be32toh(verdaux->vda_next);
	}
}

