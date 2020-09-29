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
	if (argc != 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	printf("%s\n", strsignal(strtol(argv[1], NULL, 10)));
	return (EXIT_SUCCESS);
}
