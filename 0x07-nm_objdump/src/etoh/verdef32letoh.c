#include "../etoh.h"

/**
 * verdef32letoh - convert 32-bit little-endian ver defs to host byte order
 *
 * @verdef: pointer to 32-bit little-endian ver defs
 */
void verdef32letoh(Elf32_Verdef *verdef)
{
	if (verdef)
	{
		verdef->vd_version = le16toh(verdef->vd_version);
		verdef->vd_flags = le16toh(verdef->vd_flags);
		verdef->vd_ndx = le16toh(verdef->vd_ndx);
		verdef->vd_cnt = le16toh(verdef->vd_cnt);
		verdef->vd_hash = le32toh(verdef->vd_hash);
		verdef->vd_aux = le32toh(verdef->vd_aux);
		verdef->vd_next = le32toh(verdef->vd_next);
	}
}

