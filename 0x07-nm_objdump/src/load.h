#ifndef _LOAD_H_
#define _LOAD_H_

#include <elf.h>
#include <stdio.h>

#include "etoh.h"

int ehdr32load(const char *filename, Elf32_Ehdr *ehdr);
int ehdr64load(const char *filename, Elf64_Ehdr *ehdr);

#endif /* _LOAD_H_ */
