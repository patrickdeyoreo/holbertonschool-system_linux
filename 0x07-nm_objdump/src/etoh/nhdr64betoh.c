#include "../etoh.h"

/**
 * nhdr64betoh - convert 64-bit big-endian note header to host byte order
 *
 * @nhdr: pointer to 64-bit big-endian note header
 */
void nhdr64betoh(Elf64_Nhdr *nhdr)
{
	if (nhdr)
	{
		nhdr->n_namesz = be32toh(nhdr->n_namesz);
		nhdr->n_descsz = be32toh(nhdr->n_descsz);
		nhdr->n_type = be32toh(nhdr->n_type);
	}
}

