#ifndef _HNM_H_
#define _HNM_H_

#include <elf.h>
#include <stdio.h>
#include <stdlib.h>

#include "etoh.h"
#include "load.h"

int hnm(const char *filename);
int hnm32(const char *filename);
int hnm64(const char *filename);

#endif /* _HNM_H_ */
