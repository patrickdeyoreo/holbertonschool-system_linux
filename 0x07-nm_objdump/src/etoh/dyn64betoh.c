#include "../etoh.h"

/**
 * dyn64betoh - convert 64-bit big-endian dyn entry to host byte order
 *
 * @dyn: pointer to 64-bit big-endian dyn entry
 */
void dyn64betoh(Elf64_Dyn *dyn)
{
	if (dyn)
	{
		dyn->d_tag = be64toh(dyn->d_tag);
		dyn->d_un.d_ptr = be64toh(dyn->d_un.d_ptr);
	}
}

