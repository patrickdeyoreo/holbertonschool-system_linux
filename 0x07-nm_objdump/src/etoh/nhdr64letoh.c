#include "../etoh.h"

/**
 * nhdr64letoh - convert 64-bit little-endian note header to host byte order
 *
 * @nhdr: pointer to 64-bit little-endian note header
 */
void nhdr64letoh(Elf64_Nhdr *nhdr)
{
	if (nhdr)
	{
		nhdr->n_namesz = le32toh(nhdr->n_namesz);
		nhdr->n_descsz = le32toh(nhdr->n_descsz);
		nhdr->n_type = le32toh(nhdr->n_type);
	}
}

