#include "../etoh.h"

/**
 * syminfo32betoh - convert 32-bit big-endian dyn sym info to host byte order
 *
 * @syminfo: pointer to 32-bit big-endian dyn sym info
 */
void syminfo32betoh(Elf32_Syminfo *syminfo)
{
	if (syminfo)
	{
		syminfo->si_boundto = be16toh(syminfo->si_boundto);
		syminfo->si_flags = be16toh(syminfo->si_flags);
	}
}

