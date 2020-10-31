#include "../etoh.h"

/**
 * verneed64letoh - convert 64-bit little-endian dep sect to host byte order
 *
 * @verneed: pointer to 64-bit little-endian dep sect
 */
void verneed64letoh(Elf64_Verneed *verneed)
{
	if (verneed)
	{
		verneed->vn_version = le16toh(verneed->vn_version);
		verneed->vn_cnt = le16toh(verneed->vn_cnt);
		verneed->vn_file = le32toh(verneed->vn_file);
		verneed->vn_aux = le32toh(verneed->vn_aux);
		verneed->vn_next = le32toh(verneed->vn_next);
	}
}

