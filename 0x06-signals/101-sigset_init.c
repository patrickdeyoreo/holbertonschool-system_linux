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

	if (set && signals)
	{
		for (sigemptyset(&tmp); *signals; signals += 1)
		{
			if (sigaddset(&tmp, *signals) == -1)
				return (-1);
		}
		*set = tmp;
		return (0);
	}
	return (-1);
}
