#include "hreadelf.h"

/**
 * elf_magic - print ELF magic
 * @buffer: the ELF header
 */
void elf_magic(const unsigned char *buffer)
{
	unsigned int i;

	if (strncmp((const char *) buffer, ELFMAG, 4))
	{
		write(STDERR_FILENO, "Error: Not an ELF file\n", 23);
		exit(1);
	}

	printf("ELF Header:\n  Magic:   ");

	for (i = 0; i < 16; ++i)
		printf("%02x%c", buffer[i], i < 15 ? ' ' : '\n');
}
