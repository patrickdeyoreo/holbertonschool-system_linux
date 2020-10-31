#include "../etoh.h"

/**
 * lib32betoh - convert 32-bit big-endian SHT_MIPS_LIBLIST to host byte order
 *
 * @lib: pointer to 32-bit big-endian SHT_MIPS_LIBLIST section entry
 */
void lib32betoh(Elf32_Lib *lib)
{
	if (lib)
	{
		lib->l_name = be32toh(lib->l_name);
		lib->l_time_stamp = be32toh(lib->l_time_stamp);
		lib->l_checksum = be32toh(lib->l_checksum);
		lib->l_version = be32toh(lib->l_version);
		lib->l_flags = be32toh(lib->l_flags);
	}
}

