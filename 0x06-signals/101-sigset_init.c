#include "signal.h"

/**
 * sigset_init - initialize a sigset
 * @set: pointer to the signal set to initialize
 * @signals: zero-terminated array of signal numbers
 *
 * Return: -1 upon error, 0 otherwise
 */
int sigset_init(sigset_t *set, int *signals)
{
	sigset_t tmp;

	if (!set || !signals)
		return (-1);
	if (sigemptyset(&tmp) == -1)
		return (-1);
	while (*signals)
	{
		if (sigaddset(&tmp, *signals) == -1)
			return (-1);
		signals += 1;
	}
	*set = tmp;
	return (0);
}
