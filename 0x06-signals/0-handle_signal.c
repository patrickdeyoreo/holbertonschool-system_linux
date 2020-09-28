#include "signals.h"

/**
 * sigint_handler - print a message upon receipt of SIGINT
 * @signum: signal number
 */
static void sigint_handler(int signum)
{
	printf("Gotcha! [%d]\n", signum);
}

/**
 * handle_signal - set a handler for SIGINT
 *
 * Return: -1 on error, 0 otherwise
 */
int handle_signal(void)
{
	errno = 0;
	if (signal(SIGINT, sigint_handler) == SIG_ERR && errno != 0)
		return (-1);
	return (0);
}
