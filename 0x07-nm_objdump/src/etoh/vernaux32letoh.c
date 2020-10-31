#include "../etoh.h"

/**
 * vernaux32letoh - convert 32-bit little-endian req info to host byte order
 *
 * @vernaux: pointer to 32-bit little-endian req info
 */
void vernaux32letoh(Elf32_Vernaux *vernaux)
{
	if (vernaux)
	{
		vernaux->vna_hash = le32toh(vernaux->vna_hash);
		vernaux->vna_flags = le16toh(vernaux->vna_flags);
		vernaux->vna_other = le16toh(vernaux->vna_other);
		vernaux->vna_name = le32toh(vernaux->vna_name);
		vernaux->vna_next = le32toh(vernaux->vna_next);
	}
}

