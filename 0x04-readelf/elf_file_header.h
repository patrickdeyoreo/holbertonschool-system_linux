#ifndef _ELF_FILE_HEADER_H_
#define _ELF_FILE_HEADER_H_

#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void elf_magic(const unsigned char *buffer);
size_t elf_class(const unsigned char *buffer);
int elf_data(const unsigned char *buffer);
void elf_version(const unsigned char *buffer);
void elf_osabi(const unsigned char *buffer);
void elf_abivers(const unsigned char *buffer);
void elf_type(const unsigned char *buffer, int big_endian);
void elf_entry(const unsigned char *buffer, size_t bit_mode, int big_endian);

#endif /* _ELF_FILE_HEADER_H_ */
