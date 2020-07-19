#ifndef _OPT_H_
#define _OPT_H_

#include <stdlib.h>

/**
 * struct opt_s - a program option
 * @shortname: short option name
 * @n_args: 
 * @longname: long option name
 */
typedef struct opt_s
{
	char shortname;
	char n_args;
	const char *longname;
	const char *description;
	const char * const *args;

} opt_t;

#endif /* _OPT_H_ */
