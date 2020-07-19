#include "opt.h"

options_t *import_options(void)
{
	static options_t options = OPTIONS_INIT;

	return (&options);
}
