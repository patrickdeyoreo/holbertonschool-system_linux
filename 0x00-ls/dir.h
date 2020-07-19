#ifndef _DIR_H_
#define _DIR_H_

#include <stdlib.h>

#include "entry.h"
#include "queue.h"

/**
 * struct dir_s - an entry referring to a directory
 */
typedef struct dir_s
{
	STRUCT_ENTRY_BASE
	entry_t **contents;
	queue_node_t *subdirs;
} dir_t;

#endif /* _DIR_H_ */
