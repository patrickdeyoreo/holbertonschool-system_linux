#include "signals.h"

/**
 * sigint_handler - print a message upon receipt of SIGINT
 * @signum: signal number
 */
static void sigint_handler(int signum)
{
	printf("Caught %d\n", signum);
	fflush(stdout);
}

/**
 * main - suspend until receipt of a SIGINT
 *
 * Return: Upon failure to set a signal handler, return EXIT_FAILURE.
 * Otherwise, return EXIT_SUCCESS.
 */
int main(void)
{
	sigaction_t sigint_action;

	sigint_action.sa_handler = sigint_handler;
	sigint_action.sa_flags = 0;
	sigemptyset(&sigint_action.sa_mask);

	if (sigaction(SIGINT, &sigint_action, NULL) < 0)
		return (EXIT_FAILURE);

	pause();
	return (EXIT_SUCCESS);
}
