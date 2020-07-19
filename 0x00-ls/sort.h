#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>

typedef int (*comp_fn)(const void *, const void *);

void sort(void *base, size_t nmemb, size_t size, comp_fn comp);

#endif /* _SORT_H_ */
