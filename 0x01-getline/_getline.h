#ifndef _GETLINE_H_
#define _GETLINE_H_

#include <stdlib.h>
#include <unistd.h>

#define READ_SIZE 4096

char *_getline(const int fd);

#endif /* _GETLINE_H_ */
