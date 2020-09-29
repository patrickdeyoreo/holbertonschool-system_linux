#include "signals.h"

/**
 * signals_block - block a given set of signals from being delivered
 * @signals: zero-terminated array of signals to block
 *
 * Return: -1 on error, otherwise 0
 */
int signals_block(int *signals)
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
	return (sigprocmask(SIG_BLOCK, &mask, NULL));
}
