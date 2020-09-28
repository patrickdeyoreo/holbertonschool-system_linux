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
 * sigquit_sigaction - print the sender's PID
 * @sig: signal number
 * @info: pointer to further information about the signal
 * @ucontext: pointer to signal context information
 */
static void sigquit_sigaction(int sig, siginfo_t *info, void *ucontext)
{
	(void) sig;
	(void) ucontext;
	putstr("SIGQUIT sent by ");
	if (info)
		putint(info->si_pid);
	putstr("\n");
}

/**
 * trace_signal_sender - define a SIGQUIT handler that prints the sender's PID
 *
 * Return: 0 on success, or -1 on error
 */
int trace_signal_sender(void)
{
	sigaction_t sigquit_action;

	sigquit_action.sa_handler = NULL;
	sigquit_action.sa_sigaction = sigquit_sigaction;
	sigquit_action.sa_flags = SA_SIGINFO;
	sigemptyset(&sigquit_action.sa_mask);

	if (sigaction(SIGQUIT, &sigquit_action, NULL) < 0)
		return (-1);
	return (0);
}
