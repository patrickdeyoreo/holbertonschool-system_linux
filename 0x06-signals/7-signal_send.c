#include "signals.h"

/**
 * main - send SIGINT to a process, given its PID
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Upon failure, return EXIT_FAILURE. Otherwise, return EXIT_SUCCESS.
 */
int main(int argc, char **argv)
{
	pid_t pid = 0;

	if (argc != 2)
	{
		printf("Usage: %s <pid>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	errno = 0;
	pid = strtol(argv[1], NULL, 10);

	if (pid <= 0)
		errno = ERANGE;

	if (errno)
	{
		perror(argv[0]);
		return (EXIT_FAILURE);
	}

	if (kill(pid, SIGINT) != 0)
	{
		perror(argv[0]);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
