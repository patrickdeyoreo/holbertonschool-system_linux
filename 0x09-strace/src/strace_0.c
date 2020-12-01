#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "strace.h"
#include "syscalls.h"

/**
 * trace_syscall - trace child until next entrance into or exit from a syscall
 *
 * @child: PID of the cild process being traced
 *
 * Return: If the tracee (child) exits, return 0. Otherwise, return 1.
 */
static int trace_syscall(pid_t child)
{
	int status = 0;

	while (1)
	{
		if (ptrace(PTRACE_SYSCALL, child, 0, 0))
			return (0);
		if (wait(&status) != child)
			return (0);
		if (WIFSTOPPED(status) && WSTOPSIG(status) & 0x80)
			return (1);
		if (WIFEXITED(status))
			return (0);
	}
}

/**
 * tracer - call in tracer (parent)
 *
 * @child: PID of tracee (child)
 *
 * Return: Upon success. return EXIT_SUCCESS. Otherwise, return EXIT_FAILURE.
 */
static void tracer(pid_t child)
{
	struct user_regs_struct regs = {0};

	if (wait(NULL) == child)
	{
		setbuf(stdout, NULL);
		ptrace(PTRACE_SETOPTIONS, child, 0, PTRACE_O_TRACESYSGOOD);
		while (1)
		{
			if (!trace_syscall(child))
				break;
			if (ptrace(PTRACE_GETREGS, child, NULL, &regs))
				break;
#ifdef __x86_64__
			__extension__ printf("%llu\n", regs.orig_rax);
#else
			printf("%lu\n", regs.orig_rax);
#endif
			if (!trace_syscall(child))
				break;
		}
	}
}

/**
 * tracee - call in tracee (child)
 *
 * @exec: exec arguments
 */
static void tracee(char **exec)
{
	ptrace(PTRACE_TRACEME, 0, NULL, NULL);
	kill(getpid(), SIGSTOP);
	execve(*exec, exec, environ);
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
	child = fork();
	if (child < 0)
	{
		perror(*argv);
		return (EXIT_FAILURE);
	}
	if (child == 0)
	{
		tracee(argv + 1);
		perror(*argv);
		return (EXIT_FAILURE);
	}
	tracer(child);
	return (EXIT_SUCCESS);
}
