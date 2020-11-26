#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>

#include "strace.h"
#include "syscalls.h"

/**
 * strace_loop - execute strace loop
 *
 * @tracee: PID of tracee
 *
 * Return: Upon success. return EXIT_SUCCESS. Otherwise, return EXIT_FAILURE.
 */
static int strace_loop(pid_t tracee, struct user_regs_struct *regs)
{
	while (true)
	{
		if (ptrace(PTRACE_SYSCALL, tracee, NULL, NULL))
			return (EXIT_SUCCESS);
		if (wait(NULL) != tracee)
			return (EXIT_FAILURE);
		if (ptrace(PTRACE_GETREGS, tracee, NULL, regs))
			return (EXIT_FAILURE);
#ifdef __x86_64__
		__extension__ printf("%llu\n", regs->orig_rax);
#else
		printf("%lu\n", regs->orig_rax);
#endif
		if (ptrace(PTRACE_SYSCALL, tracee, NULL, NULL) == -1)
			return (EXIT_FAILURE);
		if (wait(NULL) != tracee)
			return (EXIT_FAILURE);
	}
}

/**
 * strace - fork, exec, and trace
 *
 * @exec: exec argument vector
 *
 * Return: Upon success. return EXIT_SUCCESS. Otherwise, return EXIT_FAILURE.
 */
int strace(char **exec)
{
	struct user_regs_struct regs = {0};
	pid_t child = fork();

	if (child == 0)
	{
		ptrace(PTRACE_TRACEME, 0, NULL, NULL);
		execve(exec[0], exec, environ);
		return (EXIT_FAILURE);
	}
	if (child == -1)
		return (EXIT_FAILURE);
	if (wait(NULL) == -1)
		return (EXIT_FAILURE);
	if (ptrace(PTRACE_GETREGS, child, NULL, &regs))
		return (EXIT_FAILURE);
#ifdef __x86_64__
	__extension__ printf("%llu\n", regs.orig_rax);
#else
	printf("%lu\n", regs.orig_rax);
#endif
	return (strace_loop(child, &regs));
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
	if (argc > 1)
		return (strace(argv + 1));
	fprintf(stderr, "usage: %s PROG [ARGS]\n", *argv);
	return (EXIT_FAILURE);
}
