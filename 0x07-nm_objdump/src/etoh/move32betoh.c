#include "../etoh.h"

/**
 * move32betoh - convert 32-bit big-endian move records to host byte order
 *
 * @move: pointer to 32-bit big-endian move records
 */
void move32betoh(Elf32_Move *move)
{
	if (move)
	{
		move->m_value = be64toh(move->m_value);
		move->m_info = be32toh(move->m_info);
		move->m_poffset = be32toh(move->m_poffset);
		move->m_repeat = be16toh(move->m_repeat);
		move->m_stride = be16toh(move->m_stride);
	}
}

