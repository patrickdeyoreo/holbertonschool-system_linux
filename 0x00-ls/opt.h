#ifndef _OPT_H_
#define _OPT_H_

#include <stdbool.h>
#include <stdlib.h>

/**
 * struct opt_s - a program option
 * @name: short option name
 * @description: option description
 * @enabled: option state
 */
typedef struct opt_s
{
	const char name;
	const char *description;
	bool enabled;
} opt_t;

#define OPTIONS_INIT {							\
	{'1', "list one entry per line", false},			\
	{'A', "list all entries except '.' and '..'", false},		\
	{'a', "list all entries", false},				\
	{'l', "list entries in a long format", false},			\
	{'R', "list subdirectory contents recursively", false},		\
	{'r', "list entries in reverse order", false},			\
	{'S', "sort by file size (largest first)", false},		\
	{'t', "sort by modification time (newest first)", false},	\
	{0}								\
}
#define OPTIONS_SIZE 9

typedef opt_t options_t[OPTIONS_SIZE];

options_t *import_options(void);

#endif /* _OPT_H_ */
