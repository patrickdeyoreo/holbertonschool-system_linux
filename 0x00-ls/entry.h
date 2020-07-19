#ifndef _ENTRY_H_
#define _ENTRY_H_

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define STRUCT_ENTRY_BASE	\
	struct dirent *entry;	\
	struct stat *info;

/**
 * struct entry_s - a directory entry
 */
typedef struct entry_s
{
	STRUCT_ENTRY_BASE
} entry_t;

#endif /* _ENTRY_H_ */
