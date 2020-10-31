#include "../etoh.h"

/**
 * dyn32letoh - convert 32-bit little-endian dyn entry to host byte order
 *
 * @dyn: pointer to 32-bit little-endian dyn entry
 */
void dyn32letoh(Elf32_Dyn *dyn)
{
	if (dyn)
	{
		dyn->d_tag = le32toh(dyn->d_tag);
		dyn->d_un.d_ptr = le32toh(dyn->d_un.d_ptr);
	}
}

