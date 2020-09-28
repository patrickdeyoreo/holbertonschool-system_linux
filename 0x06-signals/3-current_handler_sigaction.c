#include "signals.h"

/**
 * current_handler_sigaction - retrieve the current handler of SIGINT
 *
 * Return: NULL on error, pointer to the current handler of SIGINT otherwise
 */
void (*current_handler_sigaction(void))(int)
{
	sigaction_t old_action;

	if (sigaction(SIGINT, NULL, &old_action) < 0)
		return (NULL);
	return (old_action.sa_handler);
}
