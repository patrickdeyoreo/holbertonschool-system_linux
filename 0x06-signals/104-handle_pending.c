#include "signals.h"

#ifndef NSIG
#ifndef _NSIG
#ifndef CHAR_BIT
#define CHAR_BIT (sizeof(char) * 8)
#endif
#define _NSIG (sizeof(sigset_t) * CHAR_BIT)
#endif
#define NSIG _NSIG
#endif

/**
 * handle_pending - set up a handler for all pending signals
 * @handler - pointer to a signal handler
 *
 * Return: -1 upon error, otherwise 0
 */
int handle_pending(sighandler_t	handler)
{
	sigaction_t action;
	sigset_t pending;
	unsigned int signum = 0;

	action.sa_handler = handler;
	action.sa_flags = 0;

	if (sigemptyset(&action.sa_mask) == -1)
		return (-1);

	if (sigpending(&pending) == -1)
		return (-1);

	while (++signum < NSIG)
	{
		switch (sigismember(&pending, signum))
		{
		case -1:
			return (-1);
		case 1:
			sigaction(signum, &action, NULL);
		}
	}
	return (0);
}
