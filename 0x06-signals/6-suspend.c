#include "signals.h"

#define putstr(s) fputs((s), stdout)

/**
 * putint - print an integer on standard output
 * @n: the integer to print
 */
static void putint(int n)
{
	int sign = n > -1 ? 1 : -1;
	char chr = (n % 10) * sign + '0';

	if (n < 0)
		putchar('-');
	if (n / 10)
		putint((n / 10) * sign);
	putchar(chr);
}

/**
 * sigint_handler - print a message upon receipt of SIGINT
 * @signum: signal number
 */
static void sigint_handler(int signum)
{
	putstr("Caught ");
	putint(signum);
	putstr("\n");
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
	sigint_action.sa_sigaction = NULL;
	sigint_action.sa_flags = 0;
	sigemptyset(&sigint_action.sa_mask);

	if (sigaction(SIGINT, &sigint_action, NULL) < 0)
		return (EXIT_FAILURE);

	pause();
	return (EXIT_SUCCESS);
}
