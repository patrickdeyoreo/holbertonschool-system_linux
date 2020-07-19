#ifndef _MEM_H_
#define _MEM_H_

#include <stdlib.h>

int _memcmp(const void *base1, const void *base2, size_t n);
void *_memcpy(void *dest, const void *src, size_t n);
void _memswap(void *base1, void *base2, size_t n);

#endif /* _MEM_H_ */
