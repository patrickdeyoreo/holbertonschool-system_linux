#include "../etoh.h"

/**
 * nhdr32letoh - convert 32-bit little-endian note header to host byte order
 *
 * @nhdr: pointer to 32-bit little-endian note header
 */
void nhdr32letoh(Elf32_Nhdr *nhdr)
{
	if (nhdr)
	{
		nhdr->n_namesz = le32toh(nhdr->n_namesz);
		nhdr->n_descsz = le32toh(nhdr->n_descsz);
		nhdr->n_type = le32toh(nhdr->n_type);
	}
}

