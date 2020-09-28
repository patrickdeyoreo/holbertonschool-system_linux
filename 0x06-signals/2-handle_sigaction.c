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
 * handle_sigaction - set a handler for SIGINT
 *
 * Return: -1 on error, 0 otherwise
 */
int handle_sigaction(void)
{
	sigaction_t sigint_action;

	sigint_action.sa_handler = sigint_handler;
	sigint_action.sa_sigaction = NULL;
	sigint_action.sa_flags = 0;
	sigint_action.sa_restorer = NULL;
	sigemptyset(&sigint_action.sa_mask);

	return (sigaction(SIGINT, &sigint_action, NULL) < 0 ? -1 : 0);
}
