#include "../etoh.h"

/**
 * syminfo64letoh - convert 64-bit little-endian sym info to host byte order
 *
 * @syminfo: pointer to 64-bit little-endian dyn sym info
 */
void syminfo64letoh(Elf64_Syminfo *syminfo)
{
	if (syminfo)
	{
		syminfo->si_boundto = le16toh(syminfo->si_boundto);
		syminfo->si_flags = le16toh(syminfo->si_flags);
	}
}

