#include <limits.h>

#include "signals.h"

#ifndef NSIG
#ifndef _NSIG
#ifndef CHAR_BIT
#define CHAR_BIT sizeof(char) * 8
#endif
#define _NSIG (CHAR_BIT * sizeof(sigset_t))
#endif
#define NSIG _NSIG
#endif

/**
 * default_sigaction - print signal information
 * @sig: signal number
 * @info: pointer to further information about the signal
 * @ucontext: pointer to signal context information
 */
static void default_sigaction(int sig, siginfo_t *info, void *ucontext)
{
	(void) sig;
	(void) ucontext;
	psiginfo(info, "Caught");
}

/**
 * all_in_one - set up a handler for all signals that may be caught
 */
void all_in_one(void)
{
	sigaction_t default_action;
	unsigned int signum = 0;

	default_action.sa_sigaction = default_sigaction;
	default_action.sa_flags = SA_SIGINFO;
	sigemptyset(&default_action.sa_mask);

	while (signum++ < NSIG)
		sigaction(signum, &default_action, NULL);
}
