#ifndef _ENTRY_H_
#define _ENTRY_H_

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "queue.h"

/**
 * union entry_s - an entry describing either a file or a directory
 * @common: information common to all files
 * @subtree: common file information followed by directory-specific information
 */
typedef union entry_s
{
	struct file_s *common;
	struct dir_s *subtree;
} entry_t;

/**
 * struct file_s - an entry describing a file
 * @entry: the directory entry as returned by readdir
 * @stat: status of the file as returned by lstat
 */
typedef struct file_s
{
	struct dirent *entry;
	struct stat *stat;
} file_t;


/**
 * struct dir_s - an entry describing a directory
 * @entry: the directory entry as returned by readdir
 * @stat: status of the file as returned by lstat
 * @contents: contents of the directory
 * @subdirs: subdirectories queued for processing
 */
typedef struct dir_s
{
	struct dirent *entry;
	struct stat *stat;
	entry_t **contents;
	queue_node_t *subdirs;
} dir_t;

#endif /* _ENTRY_H_ */
