#include "../etoh.h"

/**
 * verdef32betoh - convert 32-bit big-endian ver defs to host byte order
 *
 * @verdef: pointer to 32-bit big-endian ver defs
 */
void verdef32betoh(Elf32_Verdef *verdef)
{
	if (verdef)
	{
		verdef->vd_version = be16toh(verdef->vd_version);
		verdef->vd_flags = be16toh(verdef->vd_flags);
		verdef->vd_ndx = be16toh(verdef->vd_ndx);
		verdef->vd_cnt = be16toh(verdef->vd_cnt);
		verdef->vd_hash = be32toh(verdef->vd_hash);
		verdef->vd_aux = be32toh(verdef->vd_aux);
		verdef->vd_next = be32toh(verdef->vd_next);
	}
}

