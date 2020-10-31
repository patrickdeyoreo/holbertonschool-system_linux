#include "../etoh.h"

/**
 * dyn32betoh - convert 32-bit big-endian dyn entry to host byte order
 *
 * @dyn: pointer to 32-bit big-endian dyn entry
 */
void dyn32betoh(Elf32_Dyn *dyn)
{
	if (dyn)
	{
		dyn->d_tag = be32toh(dyn->d_tag);
		dyn->d_un.d_ptr = be32toh(dyn->d_un.d_ptr);
	}
}

