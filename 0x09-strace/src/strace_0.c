#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>

#include "strace.h"
#include "syscalls.h"

/**
 * strace - trace system calls
 *
 * @tracee: PID of tracee
 *
 * Return: Upon success. return EXIT_SUCCESS. Otherwise, return EXIT_FAILURE.
 */
int strace(pid_t tracee)
{
	struct user_regs_struct regs = {0};
	int status = 0;

	if (wait(NULL) == -1)
		return (EXIT_FAILURE);

	while (1)
	{
		if (ptrace(PTRACE_SYSCALL, tracee, NULL, NULL))
			return (EXIT_SUCCESS);
		if (wait(&status) != tracee)
			return (EXIT_FAILURE);
		if (WIFEXITED(status))
			return (EXIT_SUCCESS);
		memset(&regs, 0, sizeof(regs));
		if (ptrace(PTRACE_GETREGS, tracee, NULL, &regs))
			return (EXIT_FAILURE);
#ifdef __x86_64__
		__extension__ printf("%llu\n", regs.orig_rax);
#else
		printf("%lu\n", regs.orig_rax);
#endif
		if (ptrace(PTRACE_SYSCALL, tracee, NULL, NULL))
			return (EXIT_SUCCESS);
		if (wait(&status) != tracee)
			return (EXIT_FAILURE);
		if (WIFEXITED(status))
			return (EXIT_SUCCESS);
	}
}

/**
 * main - entry point
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Upon success. return EXIT_SUCCESS. Otherwise, return EXIT_FAILURE.
 */
int main(int argc, char **argv)
{
	pid_t child = 0;

	if (argc < 2)
	{
		fprintf(stderr, "usage: %s PROG [ARGS]\n", *argv);
		return (EXIT_FAILURE);
	}
	setbuf(stdout, NULL);
	child = fork();
	if (child == -1)
	{
		perror(*argv);
		return (EXIT_FAILURE);
	}
	if (child == 0)
	{
		ptrace(PTRACE_TRACEME, 0, NULL, NULL);
		execve(argv[1], argv + 1, environ);
		perror(*argv);
		return (EXIT_FAILURE);
	}
	return strace(child);
}
