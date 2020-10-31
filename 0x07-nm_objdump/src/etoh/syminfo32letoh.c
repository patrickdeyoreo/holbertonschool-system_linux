#include "../etoh.h"

/**
 * syminfo32letoh - convert 32-bit little-endian sym info to host byte order
 *
 * @syminfo: pointer to 32-bit little-endian dyn sym info
 */
void syminfo32letoh(Elf32_Syminfo *syminfo)
{
	if (syminfo)
	{
		syminfo->si_boundto = le16toh(syminfo->si_boundto);
		syminfo->si_flags = le16toh(syminfo->si_flags);
	}
}

