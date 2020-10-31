#include "../etoh.h"

/**
 * verneed64betoh - convert 64-bit big-endian dep sect to host byte order
 *
 * @verneed: pointer to 64-bit big-endian dep sect
 */
void verneed64betoh(Elf64_Verneed *verneed)
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

