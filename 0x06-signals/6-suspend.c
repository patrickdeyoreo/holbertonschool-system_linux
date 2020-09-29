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
 * sigint_sigaction - print a message upon receipt of SIGINT
 * @sig: signal number
 * @info: pointer to further information about the signal
 * @ucontext: pointer to signal context information
 */
static void sigint_sigaction(int sig, siginfo_t *info, void *ucontext)
{
	(void) info;
	(void) ucontext;
	putstr("Caught ");
	putint(sig);
	putstr("\n");
}

/**
 * main - suspend until receipt of a SIGINT
 *
 * Return: always 1
 */
int main(void)
{
	sigaction_t sigint_action;

	sigint_action.sa_handler = NULL;
	sigint_action.sa_sigaction = sigint_sigaction;
	sigint_action.sa_flags = SA_SIGINFO;
	sigemptyset(&sigint_action.sa_mask);

	if (sigaction(SIGINT, &sigint_action, NULL) < 0)
		return (EXIT_FAILURE);

	pause();
	return (EXIT_SUCCESS);
}
