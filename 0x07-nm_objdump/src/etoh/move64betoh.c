#include "../etoh.h"

/**
 * move64betoh - convert 64-bit big-endian move records to host byte order
 *
 * @move: pointer to 64-bit big-endian move records
 */
void move64betoh(Elf64_Move *move)
{
	if (move)
	{
		move->m_value = be64toh(move->m_value);
		move->m_info = be64toh(move->m_info);
		move->m_poffset = be64toh(move->m_poffset);
		move->m_repeat = be16toh(move->m_repeat);
		move->m_stride = be16toh(move->m_stride);
	}
}

