#include "../etoh.h"

/**
 * move32letoh - convert 32-bit little-endian move records to host byte order
 *
 * @move: pointer to 32-bit little-endian move records
 */
void move32letoh(Elf32_Move *move)
{
	if (move)
	{
		move->m_value = le64toh(move->m_value);
		move->m_info = le32toh(move->m_info);
		move->m_poffset = le32toh(move->m_poffset);
		move->m_repeat = le16toh(move->m_repeat);
		move->m_stride = le16toh(move->m_stride);
	}
}

