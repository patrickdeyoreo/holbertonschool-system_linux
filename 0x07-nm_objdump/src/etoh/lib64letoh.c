#include "../etoh.h"

/**
 * lib64letoh - convert 64-bit little-endian SHT_MIPS_LIBLIST to host byteorder
 *
 * @lib: pointer to 64-bit little-endian SHT_MIPS_LIBLIST section entry
 */
void lib64letoh(Elf64_Lib *lib)
{
	if (lib)
	{
		lib->l_name = le32toh(lib->l_name);
		lib->l_time_stamp = le32toh(lib->l_time_stamp);
		lib->l_checksum = le32toh(lib->l_checksum);
		lib->l_version = le32toh(lib->l_version);
		lib->l_flags = le32toh(lib->l_flags);
	}
}

