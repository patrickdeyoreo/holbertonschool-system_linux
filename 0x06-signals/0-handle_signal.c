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
	putstr("Gotcha! [");
	putint(signum);
	putstr("]\n");
}

/**
 * handle_signal - set a handler for SIGINT
 *
 * Return: -1 on error, 0 otherwise
 */
int handle_signal(void)
{
	if (signal(SIGINT, sigint_handler) == SIG_ERR)
		return (-1);
	return (0);
}
