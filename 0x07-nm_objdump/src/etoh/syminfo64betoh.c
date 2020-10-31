#include "../etoh.h"

/**
 * syminfo64betoh - convert 64-bit big-endian dyn sym info to host byte order
 *
 * @syminfo: pointer to 64-bit big-endian dyn sym info
 */
void syminfo64betoh(Elf64_Syminfo *syminfo)
{
	if (syminfo)
	{
		syminfo->si_boundto = be16toh(syminfo->si_boundto);
		syminfo->si_flags = be16toh(syminfo->si_flags);
	}
}

