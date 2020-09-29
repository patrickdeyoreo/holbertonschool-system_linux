#include "signals.h"

/**
 * main - print a description of a given signal
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Upon failure, return EXIT_FAILURE. Otherwise, return EXIT_SUCCESS.
 */
int main(int argc, char **argv)
{
	long int signum = strtol(argv[1], NULL, 10);

	if (argc != 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	signum = strtol(argv[1], NULL, 10);
	printf("%ld: %s\n", signum, strsignal(signum));
	return (EXIT_SUCCESS);
}
