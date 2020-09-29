#include "signals.h"

/**
 * signals_unblock - unblock a given set of signals from being delivered
 * @signals: zero-terminated array of signals to unblock
 *
 * Return: -1 upon error, 0 otherwise
 */
int signals_unblock(int *signals)
{
	sigset_t mask;

	if (!signals)
		return (-1);
	if (sigemptyset(&mask) == -1)
		return (-1);
	while (*signals)
	{
		if (sigaddset(&mask, *signals) == -1)
			return (-1);
		signals += 1;
	}
	return (sigprocmask(SIG_UNBLOCK, &mask, NULL));
}
