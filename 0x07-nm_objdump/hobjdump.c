#include "hobjdump.h"

/**
 * hobjdump - display information from object files
 *
 * argc: argument count
 * argv: argument vector
 *
 * Return: always 1
 */
int hobjdump(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	return (1);
}

/**
 * main - entry point
 *
 * argc: argument count
 * argv: argument vector
 *
 * Return: always 1
 */
int main(int argc, char **argv)
{
	return (hobjdump(argc, argv));
}
