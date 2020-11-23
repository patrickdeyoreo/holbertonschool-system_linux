#include <sys/user.h>

#include "syscalls.h"

/**
 * syscall_table - get a pointer to the syscall table
 *
 * Return: pointer to the syscall table
 */
syscall_table_t *syscall_table(void)
{
	static syscall_table_t table = SYSCALL_TABLE_INIT;

	return (&table);
}

/**
 * param_reg_offset_table - get a pointer to the param regs offset table
 *
 * Return: pointer to the param regs offset table
 */
param_reg_offset_table_t *param_reg_offset_table(void)
{
	static param_reg_offset_table_t table = PARAM_REG_OFFSET_TABLE_INIT;

	return (&table);
}
