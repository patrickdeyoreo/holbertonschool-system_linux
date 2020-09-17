#ifndef _LIBASM_H_
#define _LIBASM_H_

#include <stdio.h>
#include <stdlib.h>

size_t asm_strlen(const char *str);
int asm_strcmp(const char *s1, const char *s2);
int asm_strncmp(const char *s1, const char *s2, size_t n);

#endif /* _LIBASM_H_ */
