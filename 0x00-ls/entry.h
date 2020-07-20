#ifndef _ENTRY_H_
#define _ENTRY_H_

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "queue.h"

#define NAME_SIZE 256

/**
 * struct file_s - an entry describing a file
 * @name: name of the file
 * @info: file information
 */
typedef struct file_s
{
	char name[NAME_SIZE];
	struct stat info;
} file_t;


/**
 * struct dir_s - an entry describing a directory
 * @name: name of the directory
 * @info: directory information
 * @entries: directory entries
 * @subdirs: subdirectory list
 */
typedef struct dir_s
{
	char name[NAME_SIZE];
	struct stat info;
	union entry_s **entries;
	queue_node_t *subdirs;
} dir_t;

/**
 * union entry_s - an entry describing a directory entry
 * @file: common file information
 * @dir: common file information with additional directory-specific information
 */
typedef union entry_s
{
	file_t file;
	dir_t dir;
} entry_t;

#endif /* _ENTRY_H_ */
