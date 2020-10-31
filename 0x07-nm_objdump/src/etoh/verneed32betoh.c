#include "../etoh.h"

/**
 * verneed32betoh - convert 32-bit big-endian dep sect to host byte order
 *
 * @verneed: pointer to 32-bit big-endian dep sect
 */
void verneed32betoh(Elf32_Verneed *verneed)
{
	if (verneed)
	{
		verneed->vn_version = be16toh(verneed->vn_version);
		verneed->vn_cnt = be16toh(verneed->vn_cnt);
		verneed->vn_file = be32toh(verneed->vn_file);
		verneed->vn_aux = be32toh(verneed->vn_aux);
		verneed->vn_next = be32toh(verneed->vn_next);
	}
}

