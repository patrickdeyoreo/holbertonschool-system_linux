#include "signals.h"

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
	if (info)
	{
		printf("SIGQUIT sent by %d\n", info->si_pid);
		fflush(stdout);
	}
}

/**
 * trace_signal_sender - define a SIGQUIT handler that prints the sender's PID
 *
 * Return: 0 on success, or -1 on error
 */
int trace_signal_sender(void)
{
	sigaction_t sigquit_action;

	sigquit_action.sa_sigaction = sigquit_sigaction;
	sigquit_action.sa_flags = SA_SIGINFO;
	sigemptyset(&sigquit_action.sa_mask);

	if (sigaction(SIGQUIT, &sigquit_action, NULL) < 0)
		return (-1);
	return (0);
}
