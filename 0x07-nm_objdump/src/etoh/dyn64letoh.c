#include "../etoh.h"

/**
 * dyn64letoh - convert 64-bit little-endian dyn entry to host byte order
 *
 * @dyn: pointer to 64-bit little-endian dyn entry
 */
void dyn64letoh(Elf64_Dyn *dyn)
{
	if (dyn)
	{
		dyn->d_tag = le64toh(dyn->d_tag);
		dyn->d_un.d_ptr = le64toh(dyn->d_un.d_ptr);
	}
}

