#include "signals.h"

/**
 * pid_exist - check if a process with the given PID exists
 * @pid: pid of target process
 *
 * Return: 1 if the process with the given PID exists, 0 otherwise
 */
int pid_exist(pid_t pid)
{
	return (kill(pid, 0) == 0);
}
