#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>

#include "strace.h"
#include "syscalls.h"

/**
 * strace - execute strace
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Upon success. return EXIT_SUCCESS. Otherwise, return EXIT_FAILURE.
 */
int strace(int argc, char **argv)
{
	struct user_regs_struct regs = {0};
	syscall_t const *syscall = NULL;
	param_reg_t arg = 0;
	size_t param_count = 0;
	size_t param_index = 0;
	int wstatus = 0;
	pid_t child = fork();

	if (child == 0)
	{
		ptrace(PTRACE_TRACEME, 0, NULL, NULL);
		argv[argc] = NULL;
		execvp(argv[1], argv + 1);
		return (EXIT_FAILURE);
	}
	if (child == -1)
	{
		return (EXIT_FAILURE);
	}
	if (wait(&wstatus) == -1)
	{
		return (EXIT_FAILURE);
	}
	while (ptrace(PTRACE_SYSCALL, child, NULL, NULL) == 0 &&
		wait(&wstatus) == child &&
		ptrace(PTRACE_GETREGS, child, NULL, &regs) == 0)
	{
		syscall = &(*syscall_table())[regs.orig_rax];
		printf("%s(", syscall->name);
		param_index = 0;
		param_count = syscall->param_count;
		while (param_index < param_count)
		{
			arg = *PARAM_REG_PTR(&regs, param_index);
#ifdef __x86_64__
			printf("%s%llx", arg ? "0x" : "", arg);
#else
			printf("%s%lx", arg ? "0x" : "", arg);
#endif
			param_index += 1;
			printf(param_index < param_count ? ", " : ") = ");
		}
		if (ptrace(PTRACE_SYSCALL, child, NULL, NULL) == -1 ||
			wait(&wstatus) == -1 ||
			ptrace(PTRACE_GETREGS, child, NULL, &regs) == -1)
		{
			return (EXIT_FAILURE);
		}
#ifdef __x86_64__
		printf("%s%llx\n", regs.rax ? "0x" : "", regs.rax);
#else
		printf("%s%lx\n", regs.rax ? "0x" : "", regs.rax);
#endif
	}
	return (EXIT_SUCCESS);
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
		return (strace(argc, argv));
	fprintf(stderr, "usage: %s PROG [ARGS]\n", *argv);
	return (EXIT_FAILURE);
}
