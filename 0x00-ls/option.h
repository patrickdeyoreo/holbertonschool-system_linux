#ifndef _OPT_H_
#define _OPT_H_

#include <stdbool.h>
#include <stdlib.h>

/**
 * struct option_s - a program option
 * @name: single-character identifier
 * @desc: option description
 * @enabled: option state - enabled if true and disabled otherwise
 */
typedef struct option_s
{
	char name;
	const char *desc;
	bool enabled;
} option_t;

#define OPTION_TABLE_SIZE 0xff
#define OPTION_TABLE_INIT {						\
	{'1', "list one entry per line", false},			\
	{'A', "list all entries except '.' and '..'", false},		\
	{'a', "list all entries", false},				\
	{'l', "list entries in a long format", false},			\
	{'R', "list subdirectory contents recursively", false},		\
	{'r', "list entries in reverse order", false},			\
	{'S', "sort by file size (largest first)", false},		\
	{'t', "sort by modification time (newest first)", false},	\
	{'\0', NULL, false}						\
}

typedef option_t option_table_t[OPTION_TABLE_SIZE];

option_table_t *options(void);
bool option_is_defined(int c);
bool option_is_enabled(int c);

#endif /* _OPTION_H_ */
