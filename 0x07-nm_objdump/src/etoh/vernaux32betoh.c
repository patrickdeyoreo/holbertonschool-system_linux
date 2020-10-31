#include "../etoh.h"

/**
 * vernaux32betoh - convert 32-bit big-endian req info to host byte order
 *
 * @vernaux: pointer to 32-bit big-endian req info
 */
void vernaux32betoh(Elf32_Vernaux *vernaux)
{
	if (vernaux)
	{
		vernaux->vna_hash = be32toh(vernaux->vna_hash);
		vernaux->vna_flags = be16toh(vernaux->vna_flags);
		vernaux->vna_other = be16toh(vernaux->vna_other);
		vernaux->vna_name = be32toh(vernaux->vna_name);
		vernaux->vna_next = be32toh(vernaux->vna_next);
	}
}

