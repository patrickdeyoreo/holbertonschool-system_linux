#ifndef _SYSCALLS_H_
#define _SYSCALLS_H_

#include <stddef.h>
#include <stdint.h>
#include <sys/user.h>

/* normally, MAX_PARAMS is always 6 */
#define	MAX_PARAMS 6

/**
 * enum type_e - enumerate syscall parameters and return types
 *
 * @VOID: void
 * @AIO_CONTEXT_T: aio_context_t
 * @AIO_CONTEXT_T_P: aio_context_t pointer
 * @CADDR_T: caddr_t
 * @CAP_USER_DATA_T: cap_user_data_t
 * @CAP_USER_HEADER_T: cap_user_header_t
 * @CHAR_P: char pointer
 * @CLOCKID_T: clockid_t
 * @CLOCK_T: clock_t
 * @CPU_SET_T_P: cpu_set_t pointer
 * @DEV_T: dev_t
 * @ENUM___PTRACE_REQUEST: enum___ptrace_request
 * @FD_SET_P: fd_set pointer
 * @GID_T: gid_t
 * @GID_T_P: gid_t pointer
 * @IDTYPE_T: idtype_t
 * @ID_T: id_t
 * @INT: int
 * @INT_P: int pointer
 * @KEY_SERIAL_T: key_serial_t
 * @KEY_T: key_t
 * @LOFF_T_P: loff_t pointer
 * @LONG: long
 * @LONG_P: long pointer
 * @MODE_T: mode_t
 * @MQD_T: mqd_t
 * @NFDS_T: nfds_t
 * @OFF64_T: off64_t
 * @OFF_T: off_t
 * @OFF_T_P: off_t pointer
 * @PID_T: pid_t
 * @SIGHANDLER_T: sighandler_t
 * @SIGINFO_T_P: siginfo_t pointer
 * @SIGSET_T_P: sigset_t pointer
 * @SIZE_T: size_t
 * @SIZE_T_P: size_t pointer
 * @SOCKLEN_T: socklen_t
 * @SOCKLEN_T_P: socklen_t pointer
 * @SSIZE_T: ssize_t
 * @STACK_T_P: stack_t pointer
 * @STRUCT_EPOLL_EVENT_P: struct_epoll_event pointer
 * @STRUCT_GETCPU_CACHE_P: struct_getcpu_cache pointer
 * @STRUCT_IOCB_P: struct_iocb pointer
 * @STRUCT_IOCB_PP: struct_iocb double-pointer
 * @STRUCT_IOVEC_P: struct_iovec pointer
 * @STRUCT_IO_EVENT_P: struct_io_event pointer
 * @STRUCT_ITIMERSPEC_P: struct_itimerspec pointer
 * @STRUCT_ITIMERVAL_P: struct_itimerval pointer
 * @STRUCT_KERNEL_SYM_P: struct_kernel_sym pointer
 * @STRUCT_KEXEC_SEGMENT_P: struct_kexec_segment pointer
 * @STRUCT_LINUX_DIRENT_P: struct_linux_dirent pointer
 * @STRUCT_MMSGHDR_P: struct_mmsghdr pointer
 * @STRUCT_MQ_ATTR_P: struct_mq_attr pointer
 * @STRUCT_MSGHDR_P: struct_msghdr pointer
 * @STRUCT_MSQID_DS_P: struct_msqid_ds pointer
 * @STRUCT_NFSCTL_ARG_P: struct_nfsctl_arg pointer
 * @STRUCT_OLD_LINUX_DIRENT_P: struct_old_linux_dirent pointer
 * @STRUCT_PERF_EVENT_ATTR_P: struct_perf_event_attr pointer
 * @STRUCT_POLLFD_P: struct_pollfd pointer
 * @STRUCT_RLIMIT_P: struct_rlimit pointer
 * @STRUCT_ROBUST_LIST_HEAD_P: struct_robust_list_head pointer
 * @STRUCT_ROBUST_LIST_HEAD_PP: struct_robust_list_head double-pointer
 * @STRUCT_RUSAGE_P: struct_rusage pointer
 * @STRUCT_SCHED_ATTR_P: struct_sched_attr pointer
 * @STRUCT_SCHED_PARAM_P: struct_sched_param pointer
 * @STRUCT_SEMBUF_P: struct_sembuf pointer
 * @STRUCT_SHMID_DS_P: struct_shmid_ds pointer
 * @STRUCT_SIGACTION_P: struct_sigaction pointer
 * @STRUCT_SIGEVENT_P: struct_sigevent pointer
 * @STRUCT_SOCKADDR_P: struct_sockaddr pointer
 * @STRUCT_STATFS_P: struct_statfs pointer
 * @STRUCT_STAT_P: struct_stat pointer
 * @STRUCT_SYSINFO_P: struct_sysinfo pointer
 * @STRUCT_TIMESPEC: struct_timespec
 * @STRUCT_TIMESPEC_P: struct_timespec pointer
 * @STRUCT_TIMEVAL: struct_timeval
 * @STRUCT_TIMEVAL_P: struct_timeval pointer
 * @STRUCT_TIMEX_P: struct_timex pointer
 * @STRUCT_TIMEZONE_P: struct_timezone pointer
 * @STRUCT_TMS_P: struct_tms pointer
 * @STRUCT_USER_DESC_P: struct_user_desc pointer
 * @STRUCT_USTAT_P: struct_ustat pointer
 * @STRUCT_UTIMBUF_P: struct_utimbuf pointer
 * @STRUCT_UTSNAME_P: struct_utsname pointer
 * @STRUCT_VM86_STRUCT_P: struct_vm86_struct pointer
 * @STRUCT___SYSCTL_ARGS_P: struct___sysctl_args pointer
 * @TIMER_T: timer_t
 * @TIMER_T_P: timer_t pointer
 * @TIME_T: time_t
 * @TIME_T_P: time_t pointer
 * @U64: u64
 * @UID_T: uid_t
 * @UID_T_P: uid_t pointer
 * @UINT32_T: uint32_t
 * @UNION_NFSCTL_RES_P: union_nfsctl_res pointer
 * @UNSIGNED_CHAR_P: unsigned_char pointer
 * @UNSIGNED_FLAGS: unsigned_flags
 * @UNSIGNED_INT: unsigned_int
 * @UNSIGNED_LONG: unsigned_long
 * @UNSIGNED_LONG_P: unsigned_long pointer
 * @UNSIGNED_MSG_PRIO: unsigned_msg_prio
 * @UNSIGNED_NR_EVENTS: unsigned_nr_events
 * @UNSIGNED_NSOPS: unsigned_nsops
 * @UNSIGNED_PCPU: unsigned_pcpu
 * @UNSIGNED_PMSG_PRIO: unsigned_pmsg_prio
 * @UNSIGNED_PNODE: unsigned_pnode
 * @VARARGS: varargs
 * @VOID_P: void pointer
 * @VOID_PP: void double-pointer
 */
typedef enum type_e
{
	VOID,
	AIO_CONTEXT_T,
	AIO_CONTEXT_T_P,
	CADDR_T,
	CAP_USER_DATA_T,
	CAP_USER_HEADER_T,
	CHAR_P,
	CLOCKID_T,
	CLOCK_T,
	CPU_SET_T_P,
	DEV_T,
	ENUM___PTRACE_REQUEST,
	FD_SET_P,
	GID_T,
	GID_T_P,
	IDTYPE_T,
	ID_T,
	INT,
	INT_P,
	KEY_SERIAL_T,
	KEY_T,
	LOFF_T_P,
	LONG,
	LONG_P,
	MODE_T,
	MQD_T,
	NFDS_T,
	OFF64_T,
	OFF_T,
	OFF_T_P,
	PID_T,
	SIGHANDLER_T,
	SIGINFO_T_P,
	SIGSET_T_P,
	SIZE_T,
	SIZE_T_P,
	SOCKLEN_T,
	SOCKLEN_T_P,
	SSIZE_T,
	STACK_T_P,
	STRUCT_EPOLL_EVENT_P,
	STRUCT_GETCPU_CACHE_P,
	STRUCT_IOCB_P,
	STRUCT_IOCB_PP,
	STRUCT_IOVEC_P,
	STRUCT_IO_EVENT_P,
	STRUCT_ITIMERSPEC_P,
	STRUCT_ITIMERVAL_P,
	STRUCT_KERNEL_SYM_P,
	STRUCT_KEXEC_SEGMENT_P,
	STRUCT_LINUX_DIRENT_P,
	STRUCT_MMSGHDR_P,
	STRUCT_MQ_ATTR_P,
	STRUCT_MSGHDR_P,
	STRUCT_MSQID_DS_P,
	STRUCT_NFSCTL_ARG_P,
	STRUCT_OLD_LINUX_DIRENT_P,
	STRUCT_PERF_EVENT_ATTR_P,
	STRUCT_POLLFD_P,
	STRUCT_RLIMIT_P,
	STRUCT_ROBUST_LIST_HEAD_P,
	STRUCT_ROBUST_LIST_HEAD_PP,
	STRUCT_RUSAGE_P,
	STRUCT_SCHED_ATTR_P,
	STRUCT_SCHED_PARAM_P,
	STRUCT_SEMBUF_P,
	STRUCT_SHMID_DS_P,
	STRUCT_SIGACTION_P,
	STRUCT_SIGEVENT_P,
	STRUCT_SOCKADDR_P,
	STRUCT_STATFS_P,
	STRUCT_STAT_P,
	STRUCT_SYSINFO_P,
	STRUCT_TIMESPEC,
	STRUCT_TIMESPEC_P,
	STRUCT_TIMEVAL,
	STRUCT_TIMEVAL_P,
	STRUCT_TIMEX_P,
	STRUCT_TIMEZONE_P,
	STRUCT_TMS_P,
	STRUCT_USER_DESC_P,
	STRUCT_USTAT_P,
	STRUCT_UTIMBUF_P,
	STRUCT_UTSNAME_P,
	STRUCT_VM86_STRUCT_P,
	STRUCT___SYSCTL_ARGS_P,
	TIMER_T,
	TIMER_T_P,
	TIME_T,
	TIME_T_P,
	U64,
	UID_T,
	UID_T_P,
	UINT32_T,
	UNION_NFSCTL_RES_P,
	UNSIGNED_CHAR_P,
	UNSIGNED_FLAGS,
	UNSIGNED_INT,
	UNSIGNED_LONG,
	UNSIGNED_LONG_P,
	UNSIGNED_MSG_PRIO,
	UNSIGNED_NR_EVENTS,
	UNSIGNED_NSOPS,
	UNSIGNED_PCPU,
	UNSIGNED_PMSG_PRIO,
	UNSIGNED_PNODE,
	VARARGS,
	VOID_P,
	VOID_PP
} type_t;

/**
 * struct syscall_s - represent a syscall
 *
 * @name: name of the syscall
 * @num: syscall number
 * @return_type: return type
 * @param_count: number of parameters
 * @param_types: array of parameter types
 */
typedef struct syscall_s
{
	char const * const name;
	size_t const num;
	type_t const return_type;
	size_t const param_count;
	type_t const param_types[MAX_PARAMS];
} syscall_t;

#ifdef __x86_64__

/**
 * enum param_reg_index_e - enumerate parameter register indices
 *
 * @PARAM_REG_RDI: rdi register
 * @PARAM_REG_RSI: rsi register
 * @PARAM_REG_RDX: rdx register
 * @PARAM_REG_RCX: rcx register
 * @PARAM_REG_R8: r8 register
 * @PARAM_REG_R9: r9 register
 */
enum param_reg_index_e
{
	PARAM_REG_RDI,
	PARAM_REG_RSI,
	PARAM_REG_RDX,
	PARAM_REG_RCX,
	PARAM_REG_R8,
	PARAM_REG_R9
};

typedef unsigned long long int param_reg_t;

#define PARAM_REG_OFFSET_TABLE_SIZE 6
#define PARAM_REG_OFFSET_TABLE_INIT					\
{									\
	&((struct user_regs_struct *) 0)->rdi - (param_reg_t *) 0,	\
	&((struct user_regs_struct *) 0)->rsi - (param_reg_t *) 0,	\
	&((struct user_regs_struct *) 0)->rdx - (param_reg_t *) 0,	\
	&((struct user_regs_struct *) 0)->rcx - (param_reg_t *) 0,	\
	&((struct user_regs_struct *) 0)->r8 - (param_reg_t *) 0,	\
	&((struct user_regs_struct *) 0)->r9 - (param_reg_t *) 0	\
}

#define PARAM_REG_PTR(regs_ptr, index)					\
	((param_reg_t *) (regs_ptr) + (*param_reg_offset_table())[index])

#define PRINT_REGISTER(reg)						\
	(printf("%llx", (reg)))

#define SYSCALL_TABLE_SIZE 318
#define SYSCALL_TABLE_INIT						\
{									\
	{"read", 0, SSIZE_T, 3,						\
		{INT, VOID_P, SIZE_T, VOID, VOID, VOID}},		\
	{"write", 1, SSIZE_T, 3,					\
		{INT, VOID_P, SIZE_T, VOID, VOID, VOID}},		\
	{"open", 2, INT, 2,						\
		{CHAR_P, INT, VOID, VOID, VOID, VOID}},			\
	{"close", 3, INT, 1,						\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"stat", 4, INT, 2,						\
		{CHAR_P, STRUCT_STAT_P, VOID, VOID, VOID, VOID}},	\
	{"fstat", 5, INT, 2,						\
		{INT, STRUCT_STAT_P, VOID, VOID, VOID, VOID}},		\
	{"lstat", 6, INT, 2,						\
		{CHAR_P, STRUCT_STAT_P, VOID, VOID, VOID, VOID}},	\
	{"poll", 7, INT, 3,						\
		{STRUCT_POLLFD_P, NFDS_T, INT, VOID, VOID, VOID}},	\
	{"lseek", 8, OFF_T, 3,						\
		{INT, OFF_T, INT, VOID, VOID, VOID}},			\
	{"mmap", 9, VOID_P, 6,						\
		{VOID_P, SIZE_T, INT, INT, INT, OFF_T}},		\
	{"mprotect", 10, INT, 3,					\
		{VOID_P, SIZE_T, INT, VOID, VOID, VOID}},		\
	{"munmap", 11, INT, 2,						\
		{VOID_P, SIZE_T, VOID, VOID, VOID, VOID}},		\
	{"brk", 12, INT, 1,						\
		{VOID_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"rt_sigaction", 13, INT, 3,					\
		{INT, STRUCT_SIGACTION_P, STRUCT_SIGACTION_P, VOID,	\
			VOID, VOID}},					\
	{"rt_sigprocmask", 14, INT, 3,					\
		{INT, SIGSET_T_P, SIGSET_T_P, VOID, VOID, VOID}},	\
	{"rt_sigreturn", 15, INT, 1,					\
		{UNSIGNED_LONG, VOID, VOID, VOID, VOID, VOID}},		\
	{"ioctl", 16, INT, 3,						\
		{INT, INT, VARARGS, VOID, VOID, VOID}},			\
	{"pread64", 17, SSIZE_T, 4,					\
		{INT, VOID_P, SIZE_T, OFF_T, VOID, VOID}},		\
	{"pwrite64", 18, SSIZE_T, 4,					\
		{INT, VOID_P, SIZE_T, OFF_T, VOID, VOID}},		\
	{"readv", 19, SSIZE_T, 3,					\
		{INT, STRUCT_IOVEC_P, INT, VOID, VOID, VOID}},		\
	{"writev", 20, SSIZE_T, 3,					\
		{INT, STRUCT_IOVEC_P, INT, VOID, VOID, VOID}},		\
	{"access", 21, INT, 2,						\
		{CHAR_P, INT, VOID, VOID, VOID, VOID}},			\
	{"pipe", 22, INT, 1,						\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"select", 23, INT, 5,						\
		{INT, FD_SET_P, FD_SET_P, FD_SET_P, STRUCT_TIMEVAL_P,	\
			VOID}},						\
	{"sched_yield", 24, INT, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"mremap", 25, VOID_P, 5,					\
		{VOID_P, SIZE_T, SIZE_T, INT, VARARGS, VOID}},		\
	{"msync", 26, INT, 3,						\
		{VOID_P, SIZE_T, INT, VOID, VOID, VOID}},		\
	{"mincore", 27, INT, 3,						\
		{VOID_P, SIZE_T, UNSIGNED_CHAR_P, VOID, VOID, VOID}},	\
	{"madvise", 28, INT, 3,						\
		{VOID_P, SIZE_T, INT, VOID, VOID, VOID}},		\
	{"shmget", 29, INT, 3,						\
		{KEY_T, SIZE_T, INT, VOID, VOID, VOID}},		\
	{"shmat", 30, VOID_P, 3,					\
		{INT, VOID_P, INT, VOID, VOID, VOID}},			\
	{"shmctl", 31, INT, 3,						\
		{INT, INT, STRUCT_SHMID_DS_P, VOID, VOID, VOID}},	\
	{"dup", 32, INT, 1,						\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"dup2", 33, INT, 2,						\
		{INT, INT, VOID, VOID, VOID, VOID}},			\
	{"pause", 34, INT, 0,						\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"nanosleep", 35, INT, 2,					\
		{STRUCT_TIMESPEC_P, STRUCT_TIMESPEC_P, VOID, VOID,	\
			VOID, VOID}},					\
	{"getitimer", 36, INT, 2,					\
		{INT, STRUCT_ITIMERVAL_P, VOID, VOID, VOID, VOID}},	\
	{"alarm", 37, UNSIGNED_INT, 1,					\
		{UNSIGNED_INT, VOID, VOID, VOID, VOID, VOID}},		\
	{"setitimer", 38, INT, 3,					\
		{INT, STRUCT_ITIMERVAL_P, STRUCT_ITIMERVAL_P, VOID,	\
			VOID, VOID}},					\
	{"getpid", 39, PID_T, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"sendfile", 40, SSIZE_T, 4,					\
		{INT, INT, OFF_T_P, SIZE_T, VOID, VOID}},		\
	{"socket", 41, INT, 3,						\
		{INT, INT, INT, VOID, VOID, VOID}},			\
	{"connect", 42, INT, 3,						\
		{INT, STRUCT_SOCKADDR_P, SOCKLEN_T, VOID, VOID, VOID}},	\
	{"accept", 43, INT, 3,						\
		{INT, STRUCT_SOCKADDR_P, SOCKLEN_T_P, VOID, VOID,	\
			VOID}},						\
	{"sendto", 44, SSIZE_T, 6,					\
		{INT, VOID_P, SIZE_T, INT, STRUCT_SOCKADDR_P,		\
			SOCKLEN_T}},					\
	{"recvfrom", 45, SSIZE_T, 6,					\
		{INT, VOID_P, SIZE_T, INT, STRUCT_SOCKADDR_P,		\
			SOCKLEN_T_P}},					\
	{"sendmsg", 46, SSIZE_T, 3,					\
		{INT, STRUCT_MSGHDR_P, INT, VOID, VOID, VOID}},		\
	{"recvmsg", 47, SSIZE_T, 3,					\
		{INT, STRUCT_MSGHDR_P, INT, VOID, VOID, VOID}},		\
	{"shutdown", 48, INT, 2,					\
		{INT, INT, VOID, VOID, VOID, VOID}},			\
	{"bind", 49, INT, 3,						\
		{INT, STRUCT_SOCKADDR_P, SOCKLEN_T, VOID, VOID, VOID}},	\
	{"listen", 50, INT, 2,						\
		{INT, INT, VOID, VOID, VOID, VOID}},			\
	{"getsockname", 51, INT, 3,					\
		{INT, STRUCT_SOCKADDR_P, SOCKLEN_T_P, VOID, VOID,	\
			VOID}},						\
	{"getpeername", 52, INT, 3,					\
		{INT, STRUCT_SOCKADDR_P, SOCKLEN_T_P, VOID, VOID,	\
			VOID}},						\
	{"socketpair", 53, INT, 4,					\
		{INT, INT, INT, INT, VOID, VOID}},			\
	{"setsockopt", 54, INT, 5,					\
		{INT, INT, INT, VOID_P, SOCKLEN_T, VOID}},		\
	{"getsockopt", 55, INT, 5,					\
		{INT, INT, INT, VOID_P, SOCKLEN_T_P, VOID}},		\
	{"clone", 56, INT, 5,						\
		{INT, VOID_P, INT, VOID_P, VARARGS, VOID}},		\
	{"fork", 57, PID_T, 0,						\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"vfork", 58, PID_T, 0,						\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"execve", 59, INT, 3,						\
		{CHAR_P, CHAR_P, CHAR_P, VOID, VOID, VOID}},		\
	{"exit", 60, VOID, 1,						\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"wait4", 61, PID_T, 4,						\
		{PID_T, INT_P, INT, STRUCT_RUSAGE_P, VOID, VOID}},	\
	{"kill", 62, INT, 2,						\
		{PID_T, INT, VOID, VOID, VOID, VOID}},			\
	{"uname", 63, INT, 1,						\
		{STRUCT_UTSNAME_P, VOID, VOID, VOID, VOID, VOID}},	\
	{"semget", 64, INT, 3,						\
		{KEY_T, INT, INT, VOID, VOID, VOID}},			\
	{"semop", 65, INT, 3,						\
		{INT, STRUCT_SEMBUF_P, UNSIGNED_NSOPS, VOID, VOID,	\
			VOID}},						\
	{"semctl", 66, INT, 4,						\
		{INT, INT, INT, VARARGS, VOID, VOID}},			\
	{"shmdt", 67, INT, 1,						\
		{VOID_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"msgget", 68, INT, 2,						\
		{KEY_T, INT, VOID, VOID, VOID, VOID}},			\
	{"msgsnd", 69, INT, 4,						\
		{INT, VOID_P, SIZE_T, INT, VOID, VOID}},		\
	{"msgrcv", 70, SSIZE_T, 5,					\
		{INT, VOID_P, SIZE_T, LONG, INT, VOID}},		\
	{"msgctl", 71, INT, 3,						\
		{INT, INT, STRUCT_MSQID_DS_P, VOID, VOID, VOID}},	\
	{"fcntl", 72, INT, 3,						\
		{INT, INT, VARARGS, VOID, VOID, VOID}},			\
	{"flock", 73, INT, 2,						\
		{INT, INT, VOID, VOID, VOID, VOID}},			\
	{"fsync", 74, INT, 1,						\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"fdatasync", 75, INT, 1,					\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"truncate", 76, INT, 2,					\
		{CHAR_P, OFF_T, VOID, VOID, VOID, VOID}},		\
	{"ftruncate", 77, INT, 2,					\
		{INT, OFF_T, VOID, VOID, VOID, VOID}},			\
	{"getdents", 78, INT, 3,					\
		{UNSIGNED_INT, STRUCT_LINUX_DIRENT_P, UNSIGNED_INT,	\
			VOID, VOID, VOID}},				\
	{"getcwd", 79, CHAR_P, 2,					\
		{CHAR_P, SIZE_T, VOID, VOID, VOID, VOID}},		\
	{"chdir", 80, INT, 1,						\
		{CHAR_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"fchdir", 81, INT, 1,						\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"rename", 82, INT, 2,						\
		{CHAR_P, CHAR_P, VOID, VOID, VOID, VOID}},		\
	{"mkdir", 83, INT, 2,						\
		{CHAR_P, MODE_T, VOID, VOID, VOID, VOID}},		\
	{"rmdir", 84, INT, 1,						\
		{CHAR_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"creat", 85, INT, 2,						\
		{CHAR_P, MODE_T, VOID, VOID, VOID, VOID}},		\
	{"link", 86, INT, 2,						\
		{CHAR_P, CHAR_P, VOID, VOID, VOID, VOID}},		\
	{"unlink", 87, INT, 1,						\
		{CHAR_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"symlink", 88, INT, 2,						\
		{CHAR_P, CHAR_P, VOID, VOID, VOID, VOID}},		\
	{"readlink", 89, SSIZE_T, 3,					\
		{CHAR_P, CHAR_P, SIZE_T, VOID, VOID, VOID}},		\
	{"chmod", 90, INT, 2,						\
		{CHAR_P, MODE_T, VOID, VOID, VOID, VOID}},		\
	{"fchmod", 91, INT, 2,						\
		{INT, MODE_T, VOID, VOID, VOID, VOID}},			\
	{"chown", 92, INT, 3,						\
		{CHAR_P, UID_T, GID_T, VOID, VOID, VOID}},		\
	{"fchown", 93, INT, 3,						\
		{INT, UID_T, GID_T, VOID, VOID, VOID}},			\
	{"lchown", 94, INT, 3,						\
		{CHAR_P, UID_T, GID_T, VOID, VOID, VOID}},		\
	{"umask", 95, MODE_T, 1,					\
		{MODE_T, VOID, VOID, VOID, VOID, VOID}},		\
	{"gettimeofday", 96, INT, 2,					\
		{STRUCT_TIMEVAL_P, STRUCT_TIMEZONE_P, VOID, VOID, VOID,	\
			VOID}},						\
	{"getrlimit", 97, INT, 2,					\
		{INT, STRUCT_RLIMIT_P, VOID, VOID, VOID, VOID}},	\
	{"getrusage", 98, INT, 2,					\
		{INT, STRUCT_RUSAGE_P, VOID, VOID, VOID, VOID}},	\
	{"sysinfo", 99, INT, 1,						\
		{STRUCT_SYSINFO_P, VOID, VOID, VOID, VOID, VOID}},	\
	{"times", 100, CLOCK_T, 1,					\
		{STRUCT_TMS_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"ptrace", 101, LONG, 4,					\
		{ENUM___PTRACE_REQUEST, PID_T, VOID_P, VOID_P, VOID,	\
			VOID}},						\
	{"getuid", 102, UID_T, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"syslog", 103, INT, 3,						\
		{INT, CHAR_P, INT, VOID, VOID, VOID}},			\
	{"getgid", 104, GID_T, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"setuid", 105, INT, 1,						\
		{UID_T, VOID, VOID, VOID, VOID, VOID}},			\
	{"setgid", 106, INT, 1,						\
		{GID_T, VOID, VOID, VOID, VOID, VOID}},			\
	{"geteuid", 107, UID_T, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"getegid", 108, GID_T, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"setpgid", 109, INT, 2,					\
		{PID_T, PID_T, VOID, VOID, VOID, VOID}},		\
	{"getppid", 110, PID_T, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"getpgrp", 111, PID_T, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"setsid", 112, PID_T, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"setreuid", 113, INT, 2,					\
		{UID_T, UID_T, VOID, VOID, VOID, VOID}},		\
	{"setregid", 114, INT, 2,					\
		{GID_T, GID_T, VOID, VOID, VOID, VOID}},		\
	{"getgroups", 115, INT, 2,					\
		{INT, GID_T, VOID, VOID, VOID, VOID}},			\
	{"setgroups", 116, INT, 2,					\
		{SIZE_T, GID_T_P, VOID, VOID, VOID, VOID}},		\
	{"setresuid", 117, INT, 3,					\
		{UID_T, UID_T, UID_T, VOID, VOID, VOID}},		\
	{"getresuid", 118, INT, 3,					\
		{UID_T_P, UID_T_P, UID_T_P, VOID, VOID, VOID}},		\
	{"setresgid", 119, INT, 3,					\
		{GID_T, GID_T, GID_T, VOID, VOID, VOID}},		\
	{"getresgid", 120, INT, 3,					\
		{GID_T_P, GID_T_P, GID_T_P, VOID, VOID, VOID}},		\
	{"getpgid", 121, PID_T, 1,					\
		{PID_T, VOID, VOID, VOID, VOID, VOID}},			\
	{"setfsuid", 122, INT, 1,					\
		{UID_T, VOID, VOID, VOID, VOID, VOID}},			\
	{"setfsgid", 123, INT, 1,					\
		{UID_T, VOID, VOID, VOID, VOID, VOID}},			\
	{"getsid", 124, PID_T, 1,					\
		{PID_T, VOID, VOID, VOID, VOID, VOID}},			\
	{"capget", 125, INT, 2,						\
		{CAP_USER_HEADER_T, CAP_USER_DATA_T, VOID, VOID, VOID,	\
			VOID}},						\
	{"capset", 126, INT, 2,						\
		{CAP_USER_HEADER_T, CAP_USER_DATA_T, VOID, VOID, VOID,	\
			VOID}},						\
	{"rt_sigpending", 127, INT, 1,					\
		{SIGSET_T_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"rt_sigtimedwait", 128, INT, 3,				\
		{SIGSET_T_P, SIGINFO_T_P, STRUCT_TIMESPEC_P, VOID,	\
			VOID, VOID}},					\
	{"rt_sigqueueinfo", 129, INT, 3,				\
		{PID_T, INT, SIGINFO_T_P, VOID, VOID, VOID}},		\
	{"rt_sigsuspend", 130, INT, 1,					\
		{SIGSET_T_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"sigaltstack", 131, INT, 2,					\
		{STACK_T_P, STACK_T_P, VOID, VOID, VOID, VOID}},	\
	{"utime", 132, INT, 2,						\
		{CHAR_P, STRUCT_UTIMBUF_P, VOID, VOID, VOID, VOID}},	\
	{"mknod", 133, INT, 3,						\
		{CHAR_P, MODE_T, DEV_T, VOID, VOID, VOID}},		\
	{"uselib", 134, INT, 1,						\
		{CHAR_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"personality", 135, INT, 1,					\
		{UNSIGNED_LONG, VOID, VOID, VOID, VOID, VOID}},		\
	{"ustat", 136, INT, 2,						\
		{DEV_T, STRUCT_USTAT_P, VOID, VOID, VOID, VOID}},	\
	{"statfs", 137, INT, 2,						\
		{CHAR_P, STRUCT_STATFS_P, VOID, VOID, VOID, VOID}},	\
	{"fstatfs", 138, INT, 2,					\
		{INT, STRUCT_STATFS_P, VOID, VOID, VOID, VOID}},	\
	{"sysfs", 139, INT, 2,						\
		{INT, CHAR_P, VOID, VOID, VOID, VOID}},			\
	{"getpriority", 140, INT, 2,					\
		{INT, INT, VOID, VOID, VOID, VOID}},			\
	{"setpriority", 141, INT, 3,					\
		{INT, INT, INT, VOID, VOID, VOID}},			\
	{"sched_setparam", 142, INT, 2,					\
		{PID_T, STRUCT_SCHED_PARAM_P, VOID, VOID, VOID, VOID}},	\
	{"sched_getparam", 143, INT, 2,					\
		{PID_T, STRUCT_SCHED_PARAM_P, VOID, VOID, VOID, VOID}},	\
	{"sched_setscheduler", 144, INT, 3,				\
		{PID_T, INT, STRUCT_SCHED_PARAM_P, VOID, VOID, VOID}},	\
	{"sched_getscheduler", 145, INT, 1,				\
		{PID_T, VOID, VOID, VOID, VOID, VOID}},			\
	{"sched_get_priority_max", 146, INT, 1,				\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"sched_get_priority_min", 147, INT, 1,				\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"sched_rr_get_interval", 148, INT, 2,				\
		{PID_T, STRUCT_TIMESPEC_P, VOID, VOID, VOID, VOID}},	\
	{"mlock", 149, INT, 2,						\
		{VOID_P, SIZE_T, VOID, VOID, VOID, VOID}},		\
	{"munlock", 150, INT, 2,					\
		{VOID_P, SIZE_T, VOID, VOID, VOID, VOID}},		\
	{"mlockall", 151, INT, 1,					\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"munlockall", 152, INT, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"vhangup", 153, INT, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"modify_ldt", 154, INT, 3,					\
		{INT, VOID_P, UNSIGNED_LONG, VOID, VOID, VOID}},	\
	{"pivot_root", 155, INT, 2,					\
		{CHAR_P, CHAR_P, VOID, VOID, VOID, VOID}},		\
	{"_sysctl", 156, INT, 1,					\
		{STRUCT___SYSCTL_ARGS_P, VOID, VOID, VOID, VOID,	\
			VOID}},						\
	{"prctl", 157, INT, 5,						\
		{INT, UNSIGNED_LONG, UNSIGNED_LONG, UNSIGNED_LONG,	\
			UNSIGNED_LONG, VOID}},				\
	{"arch_prctl", 158, INT, 2,					\
		{INT, UNSIGNED_LONG, VOID, VOID, VOID, VOID}},		\
	{"adjtimex", 159, INT, 1,					\
		{STRUCT_TIMEX_P, VOID, VOID, VOID, VOID, VOID}},	\
	{"setrlimit", 160, INT, 2,					\
		{INT, STRUCT_RLIMIT_P, VOID, VOID, VOID, VOID}},	\
	{"chroot", 161, INT, 1,						\
		{CHAR_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"sync", 162, VOID, 0,						\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"acct", 163, INT, 1,						\
		{CHAR_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"settimeofday", 164, INT, 2,					\
		{STRUCT_TIMEVAL_P, STRUCT_TIMEZONE_P, VOID, VOID, VOID,	\
			VOID}},						\
	{"mount", 165, INT, 5,						\
		{CHAR_P, CHAR_P, CHAR_P, UNSIGNED_LONG, VOID_P, VOID}},	\
	{"umount2", 166, INT, 2,					\
		{CHAR_P, INT, VOID, VOID, VOID, VOID}},			\
	{"swapon", 167, INT, 2,						\
		{CHAR_P, INT, VOID, VOID, VOID, VOID}},			\
	{"swapoff", 168, INT, 1,					\
		{CHAR_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"reboot", 169, INT, 4,						\
		{INT, INT, INT, VOID_P, VOID, VOID}},			\
	{"sethostname", 170, INT, 2,					\
		{CHAR_P, SIZE_T, VOID, VOID, VOID, VOID}},		\
	{"setdomainname", 171, INT, 2,					\
		{CHAR_P, SIZE_T, VOID, VOID, VOID, VOID}},		\
	{"iopl", 172, INT, 1,						\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"ioperm", 173, INT, 3,						\
		{UNSIGNED_LONG, UNSIGNED_LONG, INT, VOID, VOID, VOID}},	\
	{"create_module", 174, CADDR_T, 2,				\
		{CHAR_P, SIZE_T, VOID, VOID, VOID, VOID}},		\
	{"init_module", 175, INT, 3,					\
		{VOID_P, UNSIGNED_LONG, CHAR_P, VOID, VOID, VOID}},	\
	{"delete_module", 176, INT, 2,					\
		{CHAR_P, INT, VOID, VOID, VOID, VOID}},			\
	{"get_kernel_syms", 177, INT, 1,				\
		{STRUCT_KERNEL_SYM_P, VOID, VOID, VOID, VOID, VOID}},	\
	{"query_module", 178, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"quotactl", 179, INT, 4,					\
		{INT, CHAR_P, INT, CADDR_T, VOID, VOID}},		\
	{"nfsservctl", 180, LONG, 3,					\
		{INT, STRUCT_NFSCTL_ARG_P, UNION_NFSCTL_RES_P, VOID,	\
			VOID, VOID}},					\
	{"getpmsg", 181, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"putpmsg", 182, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"afs_syscall", 183, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"tuxcall", 184, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"security", 185, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"gettid", 186, PID_T, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"readahead", 187, SSIZE_T, 3,					\
		{INT, OFF64_T, SIZE_T, VOID, VOID, VOID}},		\
	{"setxattr", 188, INT, 5,					\
		{CHAR_P, CHAR_P, VOID_P, SIZE_T, INT, VOID}},		\
	{"lsetxattr", 189, INT, 5,					\
		{CHAR_P, CHAR_P, VOID_P, SIZE_T, INT, VOID}},		\
	{"fsetxattr", 190, INT, 5,					\
		{INT, CHAR_P, VOID_P, SIZE_T, INT, VOID}},		\
	{"getxattr", 191, SSIZE_T, 4,					\
		{CHAR_P, CHAR_P, VOID_P, SIZE_T, VOID, VOID}},		\
	{"lgetxattr", 192, SSIZE_T, 4,					\
		{CHAR_P, CHAR_P, VOID_P, SIZE_T, VOID, VOID}},		\
	{"fgetxattr", 193, SSIZE_T, 4,					\
		{INT, CHAR_P, VOID_P, SIZE_T, VOID, VOID}},		\
	{"listxattr", 194, SSIZE_T, 3,					\
		{CHAR_P, CHAR_P, SIZE_T, VOID, VOID, VOID}},		\
	{"llistxattr", 195, SSIZE_T, 3,					\
		{CHAR_P, CHAR_P, SIZE_T, VOID, VOID, VOID}},		\
	{"flistxattr", 196, SSIZE_T, 3,					\
		{INT, CHAR_P, SIZE_T, VOID, VOID, VOID}},		\
	{"removexattr", 197, INT, 2,					\
		{CHAR_P, CHAR_P, VOID, VOID, VOID, VOID}},		\
	{"lremovexattr", 198, INT, 2,					\
		{CHAR_P, CHAR_P, VOID, VOID, VOID, VOID}},		\
	{"fremovexattr", 199, INT, 2,					\
		{INT, CHAR_P, VOID, VOID, VOID, VOID}},			\
	{"tkill", 200, INT, 2,						\
		{INT, INT, VOID, VOID, VOID, VOID}},			\
	{"time", 201, TIME_T, 1,					\
		{TIME_T_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"futex", 202, INT, 6,						\
		{INT_P, INT, INT, STRUCT_TIMESPEC_P, INT_P, INT}},	\
	{"sched_setaffinity", 203, INT, 3,				\
		{PID_T, SIZE_T, CPU_SET_T_P, VOID, VOID, VOID}},	\
	{"sched_getaffinity", 204, INT, 3,				\
		{PID_T, SIZE_T, CPU_SET_T_P, VOID, VOID, VOID}},	\
	{"set_thread_area", 205, INT, 1,				\
		{STRUCT_USER_DESC_P, VOID, VOID, VOID, VOID, VOID}},	\
	{"io_setup", 206, INT, 2,					\
		{UNSIGNED_NR_EVENTS, AIO_CONTEXT_T_P, VOID, VOID, VOID,	\
			VOID}},						\
	{"io_destroy", 207, INT, 1,					\
		{AIO_CONTEXT_T, VOID, VOID, VOID, VOID, VOID}},		\
	{"io_getevents", 208, INT, 5,					\
		{AIO_CONTEXT_T, LONG, LONG, STRUCT_IO_EVENT_P,		\
			STRUCT_TIMESPEC_P, VOID}},			\
	{"io_submit", 209, INT, 3,					\
		{AIO_CONTEXT_T, LONG, STRUCT_IOCB_PP, VOID, VOID,	\
			VOID}},						\
	{"io_cancel", 210, INT, 3,					\
		{AIO_CONTEXT_T, STRUCT_IOCB_P, STRUCT_IO_EVENT_P, VOID,	\
			VOID, VOID}},					\
	{"get_thread_area", 211, INT, 1,				\
		{STRUCT_USER_DESC_P, VOID, VOID, VOID, VOID, VOID}},	\
	{"lookup_dcookie", 212, INT, 3,					\
		{U64, CHAR_P, SIZE_T, VOID, VOID, VOID}},		\
	{"epoll_create", 213, INT, 1,					\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"epoll_ctl_old", 214, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"epoll_wait_old", 215, VOID, 0,				\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"remap_file_pages", 216, INT, 5,				\
		{VOID_P, SIZE_T, INT, SSIZE_T, INT, VOID}},		\
	{"getdents64", 217, INT, 3,					\
		{UNSIGNED_INT, STRUCT_LINUX_DIRENT_P, UNSIGNED_INT,	\
			VOID, VOID, VOID}},				\
	{"set_tid_address", 218, LONG, 1,				\
		{INT_P, VOID, VOID, VOID, VOID, VOID}},			\
	{"restart_syscall", 219, INT, 0,				\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"semtimedop", 220, INT, 4,					\
		{INT, STRUCT_SEMBUF_P, UNSIGNED_NSOPS,			\
			STRUCT_TIMESPEC_P, VOID, VOID}},		\
	{"fadvise64", 221, INT, 4,					\
		{INT, OFF_T, OFF_T, INT, VOID, VOID}},			\
	{"timer_create", 222, INT, 3,					\
		{CLOCKID_T, STRUCT_SIGEVENT_P, TIMER_T_P, VOID, VOID,	\
			VOID}},						\
	{"timer_settime", 223, INT, 4,					\
		{TIMER_T, INT, STRUCT_ITIMERSPEC_P,			\
			STRUCT_ITIMERSPEC_P, VOID, VOID}},		\
	{"timer_gettime", 224, INT, 2,					\
		{TIMER_T, STRUCT_ITIMERSPEC_P, VOID, VOID, VOID,	\
			VOID}},						\
	{"timer_getoverrun", 225, INT, 1,				\
		{TIMER_T, VOID, VOID, VOID, VOID, VOID}},		\
	{"timer_delete", 226, INT, 1,					\
		{TIMER_T, VOID, VOID, VOID, VOID, VOID}},		\
	{"clock_settime", 227, INT, 2,					\
		{CLOCKID_T, STRUCT_TIMESPEC_P, VOID, VOID, VOID,	\
			VOID}},						\
	{"clock_gettime", 228, INT, 2,					\
		{CLOCKID_T, STRUCT_TIMESPEC_P, VOID, VOID, VOID,	\
			VOID}},						\
	{"clock_getres", 229, INT, 2,					\
		{CLOCKID_T, STRUCT_TIMESPEC_P, VOID, VOID, VOID,	\
			VOID}},						\
	{"clock_nanosleep", 230, INT, 4,				\
		{CLOCKID_T, INT, STRUCT_TIMESPEC_P, STRUCT_TIMESPEC_P,	\
			VOID, VOID}},					\
	{"exit_group", 231, VOID, 1,					\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"epoll_wait", 232, INT, 4,					\
		{INT, STRUCT_EPOLL_EVENT_P, INT, INT, VOID, VOID}},	\
	{"epoll_ctl", 233, INT, 4,					\
		{INT, INT, INT, STRUCT_EPOLL_EVENT_P, VOID, VOID}},	\
	{"tgkill", 234, INT, 3,						\
		{INT, INT, INT, VOID, VOID, VOID}},			\
	{"utimes", 235, INT, 2,						\
		{CHAR_P, STRUCT_TIMEVAL, VOID, VOID, VOID, VOID}},	\
	{"vserver", 236, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"mbind", 237, INT, 6,						\
		{VOID_P, UNSIGNED_LONG, INT, UNSIGNED_LONG_P,		\
			UNSIGNED_LONG, UNSIGNED_FLAGS}},		\
	{"set_mempolicy", 238, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"get_mempolicy", 239, INT, 5,					\
		{INT_P, UNSIGNED_LONG_P, UNSIGNED_LONG, UNSIGNED_LONG,	\
			UNSIGNED_LONG, VOID}},				\
	{"mq_open", 240, MQD_T, 2,					\
		{CHAR_P, INT, VOID, VOID, VOID, VOID}},			\
	{"mq_unlink", 241, INT, 1,					\
		{CHAR_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"mq_timedsend", 242, INT, 5,					\
		{MQD_T, CHAR_P, SIZE_T, UNSIGNED_MSG_PRIO,		\
			STRUCT_TIMESPEC_P, VOID}},			\
	{"mq_timedreceive", 243, SSIZE_T, 5,				\
		{MQD_T, CHAR_P, SIZE_T, UNSIGNED_PMSG_PRIO,		\
			STRUCT_TIMESPEC_P, VOID}},			\
	{"mq_notify", 244, INT, 2,					\
		{MQD_T, STRUCT_SIGEVENT_P, VOID, VOID, VOID, VOID}},	\
	{"mq_getsetattr", 245, INT, 3,					\
		{MQD_T, STRUCT_MQ_ATTR_P, STRUCT_MQ_ATTR_P, VOID, VOID,	\
			VOID}},						\
	{"kexec_load", 246, LONG, 4,					\
		{UNSIGNED_LONG, UNSIGNED_LONG, STRUCT_KEXEC_SEGMENT_P,	\
			UNSIGNED_LONG, VOID, VOID}},			\
	{"waitid", 247, INT, 4,						\
		{IDTYPE_T, ID_T, SIGINFO_T_P, INT, VOID, VOID}},	\
	{"add_key", 248, KEY_SERIAL_T, 5,				\
		{CHAR_P, CHAR_P, VOID_P, SIZE_T, KEY_SERIAL_T, VOID}},	\
	{"request_key", 249, KEY_SERIAL_T, 4,				\
		{CHAR_P, CHAR_P, CHAR_P, KEY_SERIAL_T, VOID, VOID}},	\
	{"keyctl", 250, LONG, 2,					\
		{INT, VARARGS, VOID, VOID, VOID, VOID}},		\
	{"ioprio_set", 251, INT, 3,					\
		{INT, INT, INT, VOID, VOID, VOID}},			\
	{"ioprio_get", 252, INT, 2,					\
		{INT, INT, VOID, VOID, VOID, VOID}},			\
	{"inotify_init", 253, INT, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"inotify_add_watch", 254, INT, 3,				\
		{INT, CHAR_P, UINT32_T, VOID, VOID, VOID}},		\
	{"inotify_rm_watch", 255, INT, 2,				\
		{INT, INT, VOID, VOID, VOID, VOID}},			\
	{"migrate_pages", 256, LONG, 4,					\
		{INT, UNSIGNED_LONG, UNSIGNED_LONG_P, UNSIGNED_LONG_P,	\
			VOID, VOID}},					\
	{"openat", 257, INT, 3,						\
		{INT, CHAR_P, INT, VOID, VOID, VOID}},			\
	{"mkdirat", 258, INT, 3,					\
		{INT, CHAR_P, MODE_T, VOID, VOID, VOID}},		\
	{"mknodat", 259, INT, 4,					\
		{INT, CHAR_P, MODE_T, DEV_T, VOID, VOID}},		\
	{"fchownat", 260, INT, 5,					\
		{INT, CHAR_P, UID_T, GID_T, INT, VOID}},		\
	{"futimesat", 261, INT, 3,					\
		{INT, CHAR_P, STRUCT_TIMEVAL, VOID, VOID, VOID}},	\
	{"newfstatat", 262, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"unlinkat", 263, INT, 3,					\
		{INT, CHAR_P, INT, VOID, VOID, VOID}},			\
	{"renameat", 264, INT, 4,					\
		{INT, CHAR_P, INT, CHAR_P, VOID, VOID}},		\
	{"linkat", 265, INT, 5,						\
		{INT, CHAR_P, INT, CHAR_P, INT, VOID}},			\
	{"symlinkat", 266, INT, 3,					\
		{CHAR_P, INT, CHAR_P, VOID, VOID, VOID}},		\
	{"readlinkat", 267, INT, 4,					\
		{INT, CHAR_P, CHAR_P, SIZE_T, VOID, VOID}},		\
	{"fchmodat", 268, INT, 4,					\
		{INT, CHAR_P, MODE_T, INT, VOID, VOID}},		\
	{"faccessat", 269, INT, 4,					\
		{INT, CHAR_P, INT, INT, VOID, VOID}},			\
	{"pselect6", 270, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"ppoll", 271, INT, 4,						\
		{STRUCT_POLLFD_P, NFDS_T, STRUCT_TIMESPEC_P,		\
			SIGSET_T_P, VOID, VOID}},			\
	{"unshare", 272, INT, 1,					\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"set_robust_list", 273, LONG, 2,				\
		{STRUCT_ROBUST_LIST_HEAD_P, SIZE_T, VOID, VOID, VOID,	\
			VOID}},						\
	{"get_robust_list", 274, LONG, 3,				\
		{INT, STRUCT_ROBUST_LIST_HEAD_PP, SIZE_T_P, VOID, VOID,	\
			VOID}},						\
	{"splice", 275, SSIZE_T, 6,					\
		{INT, LOFF_T_P, INT, LOFF_T_P, SIZE_T, UNSIGNED_INT}},	\
	{"tee", 276, SSIZE_T, 4,					\
		{INT, INT, SIZE_T, UNSIGNED_INT, VOID, VOID}},		\
	{"sync_file_range", 277, INT, 4,				\
		{INT, OFF64_T, OFF64_T, UNSIGNED_INT, VOID, VOID}},	\
	{"vmsplice", 278, SSIZE_T, 4,					\
		{INT, STRUCT_IOVEC_P, UNSIGNED_LONG, UNSIGNED_INT,	\
			VOID, VOID}},					\
	{"move_pages", 279, LONG, 6,					\
		{INT, UNSIGNED_LONG, VOID_PP, INT_P, INT_P, INT}},	\
	{"utimensat", 280, INT, 4,					\
		{INT, CHAR_P, STRUCT_TIMESPEC, INT, VOID, VOID}},	\
	{"epoll_pwait", 281, INT, 5,					\
		{INT, STRUCT_EPOLL_EVENT_P, INT, INT, SIGSET_T_P,	\
			VOID}},						\
	{"signalfd", 282, INT, 3,					\
		{INT, SIGSET_T_P, INT, VOID, VOID, VOID}},		\
	{"timerfd_create", 283, INT, 2,					\
		{INT, INT, VOID, VOID, VOID, VOID}},			\
	{"eventfd", 284, INT, 2,					\
		{UNSIGNED_INT, INT, VOID, VOID, VOID, VOID}},		\
	{"fallocate", 285, INT, 4,					\
		{INT, INT, OFF_T, OFF_T, VOID, VOID}},			\
	{"timerfd_settime", 286, INT, 4,				\
		{INT, INT, STRUCT_ITIMERSPEC_P, STRUCT_ITIMERSPEC_P,	\
			VOID, VOID}},					\
	{"timerfd_gettime", 287, INT, 2,				\
		{INT, STRUCT_ITIMERSPEC_P, VOID, VOID, VOID, VOID}},	\
	{"accept4", 288, INT, 4,					\
		{INT, STRUCT_SOCKADDR_P, SOCKLEN_T_P, INT, VOID,	\
			VOID}},						\
	{"signalfd4", 289, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"eventfd2", 290, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"epoll_create1", 291, INT, 1,					\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"dup3", 292, INT, 3,						\
		{INT, INT, INT, VOID, VOID, VOID}},			\
	{"pipe2", 293, INT, 2,						\
		{INT, INT, VOID, VOID, VOID, VOID}},			\
	{"inotify_init1", 294, INT, 1,					\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"preadv", 295, SSIZE_T, 4,					\
		{INT, STRUCT_IOVEC_P, INT, OFF_T, VOID, VOID}},		\
	{"pwritev", 296, SSIZE_T, 4,					\
		{INT, STRUCT_IOVEC_P, INT, OFF_T, VOID, VOID}},		\
	{"rt_tgsigqueueinfo", 297, INT, 4,				\
		{PID_T, PID_T, INT, SIGINFO_T_P, VOID, VOID}},		\
	{"perf_event_open", 298, INT, 5,				\
		{STRUCT_PERF_EVENT_ATTR_P, PID_T, INT, INT,		\
			UNSIGNED_LONG, VOID}},				\
	{"recvmmsg", 299, INT, 5,					\
		{INT, STRUCT_MMSGHDR_P, UNSIGNED_INT, UNSIGNED_INT,	\
			STRUCT_TIMESPEC_P, VOID}},			\
	{"fanotify_init", 300, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"fanotify_mark", 301, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"prlimit64", 302, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"name_to_handle_at", 303, VOID, 0,				\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"open_by_handle_at", 304, VOID, 0,				\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"clock_adjtime", 305, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"syncfs", 306, INT, 1,						\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"sendmmsg", 307, INT, 4,					\
		{INT, STRUCT_MMSGHDR_P, UNSIGNED_INT, UNSIGNED_INT,	\
			VOID, VOID}},					\
	{"setns", 308, INT, 2,						\
		{INT, INT, VOID, VOID, VOID, VOID}},			\
	{"getcpu", 309, INT, 3,						\
		{UNSIGNED_PCPU, UNSIGNED_PNODE, STRUCT_GETCPU_CACHE_P,	\
			VOID, VOID, VOID}},				\
	{"process_vm_readv", 310, SSIZE_T, 6,				\
		{PID_T, STRUCT_IOVEC_P, UNSIGNED_LONG, STRUCT_IOVEC_P,	\
			UNSIGNED_LONG, UNSIGNED_LONG}},			\
	{"process_vm_writev", 311, SSIZE_T, 6,				\
		{PID_T, STRUCT_IOVEC_P, UNSIGNED_LONG, STRUCT_IOVEC_P,	\
			UNSIGNED_LONG, UNSIGNED_LONG}},			\
	{"kcmp", 312, INT, 5,						\
		{PID_T, PID_T, INT, UNSIGNED_LONG, UNSIGNED_LONG,	\
			VOID}},						\
	{"finit_module", 313, INT, 3,					\
		{INT, CHAR_P, INT, VOID, VOID, VOID}},			\
	{"sched_setattr", 314, INT, 3,					\
		{PID_T, STRUCT_SCHED_ATTR_P, UNSIGNED_INT, VOID, VOID,	\
			VOID}},						\
	{"sched_getattr", 315, INT, 3,					\
		{PID_T, STRUCT_SCHED_ATTR_P, UNSIGNED_INT, VOID, VOID,	\
			VOID}},						\
	{"renameat2", 316, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"seccomp", 317, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}}			\
}

#else

/**
 * enum param_reg_index_e - enumerate parameter register indices
 *
 * @PARAM_REG_RDI: rdi register
 * @PARAM_REG_RSI: rsi register
 * @PARAM_REG_RDX: rdx register
 * @PARAM_REG_RCX: rcx register
 * @PARAM_REG_R8: r8 register
 * @PARAM_REG_R9: r9 register
 */
enum param_reg_index_e
{
	PARAM_REG_RDI,
	PARAM_REG_RSI,
	PARAM_REG_RDX,
	PARAM_REG_RCX,
	PARAM_REG_R8,
	PARAM_REG_R9
};

typedef unsigned long int param_reg_t;

#define PARAM_REG_OFFSET_TABLE_SIZE 6
#define PARAM_REG_OFFSET_TABLE_INIT					\
{									\
	&((struct user_regs_struct *) 0)->rdi - (param_reg_t *) 0,	\
	&((struct user_regs_struct *) 0)->rsi - (param_reg_t *) 0,	\
	&((struct user_regs_struct *) 0)->rdx - (param_reg_t *) 0,	\
	&((struct user_regs_struct *) 0)->rcx - (param_reg_t *) 0,	\
	&((struct user_regs_struct *) 0)->r8 - (param_reg_t *) 0,	\
	&((struct user_regs_struct *) 0)->r9 - (param_reg_t *) 0	\
}

#define PARAM_REG_PTR(regs_ptr, index)					\
	((param_reg_t *) (regs_ptr) + (*param_reg_offset_table())[index])

#define PRINT_REGISTER(reg)						\
	(printf("%lx", (reg)))

#define SYSCALL_TABLE_SIZE 355
#define SYSCALL_TABLE_INIT						\
{									\
	{"restart_syscall", 0, INT, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"exit", 1, VOID, 1,						\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"fork", 2, PID_T, 0,						\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"read", 3, SSIZE_T, 3,						\
		{INT, VOID_P, SIZE_T, VOID, VOID, VOID}},		\
	{"write", 4, SSIZE_T, 3,					\
		{INT, VOID_P, SIZE_T, VOID, VOID, VOID}},		\
	{"open", 5, INT, 2,						\
		{CHAR_P, INT, VOID, VOID, VOID, VOID}},			\
	{"close", 6, INT, 1,						\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"waitpid", 7, PID_T, 3,					\
		{PID_T, INT_P, INT, VOID, VOID, VOID}},			\
	{"creat", 8, INT, 2,						\
		{CHAR_P, MODE_T, VOID, VOID, VOID, VOID}},		\
	{"link", 9, INT, 2,						\
		{CHAR_P, CHAR_P, VOID, VOID, VOID, VOID}},		\
	{"unlink", 10, INT, 1,						\
		{CHAR_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"execve", 11, INT, 3,						\
		{CHAR_P, CHAR_P, CHAR_P, VOID, VOID, VOID}},		\
	{"chdir", 12, INT, 1,						\
		{CHAR_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"time", 13, TIME_T, 1,						\
		{TIME_T_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"mknod", 14, INT, 3,						\
		{CHAR_P, MODE_T, DEV_T, VOID, VOID, VOID}},		\
	{"chmod", 15, INT, 2,						\
		{CHAR_P, MODE_T, VOID, VOID, VOID, VOID}},		\
	{"lchown", 16, INT, 3,						\
		{CHAR_P, UID_T, GID_T, VOID, VOID, VOID}},		\
	{"break", 17, VOID, 0,						\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"oldstat", 18, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"lseek", 19, OFF_T, 3,						\
		{INT, OFF_T, INT, VOID, VOID, VOID}},			\
	{"getpid", 20, PID_T, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"mount", 21, INT, 5,						\
		{CHAR_P, CHAR_P, CHAR_P, UNSIGNED_LONG, VOID_P, VOID}},	\
	{"umount", 22, INT, 1,						\
		{CHAR_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"setuid", 23, INT, 1,						\
		{UID_T, VOID, VOID, VOID, VOID, VOID}},			\
	{"getuid", 24, UID_T, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"stime", 25, INT, 1,						\
		{TIME_T_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"ptrace", 26, LONG, 4,						\
		{ENUM___PTRACE_REQUEST, PID_T, VOID_P, VOID_P, VOID,	\
			VOID}},						\
	{"alarm", 27, UNSIGNED_INT, 1,					\
		{UNSIGNED_INT, VOID, VOID, VOID, VOID, VOID}},		\
	{"oldfstat", 28, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"pause", 29, INT, 0,						\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"utime", 30, INT, 2,						\
		{CHAR_P, STRUCT_UTIMBUF_P, VOID, VOID, VOID, VOID}},	\
	{"stty", 31, VOID, 0,						\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"gtty", 32, VOID, 0,						\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"access", 33, INT, 2,						\
		{CHAR_P, INT, VOID, VOID, VOID, VOID}},			\
	{"nice", 34, INT, 1,						\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"ftime", 35, VOID, 0,						\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"sync", 36, VOID, 0,						\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"kill", 37, INT, 2,						\
		{PID_T, INT, VOID, VOID, VOID, VOID}},			\
	{"rename", 38, INT, 2,						\
		{CHAR_P, CHAR_P, VOID, VOID, VOID, VOID}},		\
	{"mkdir", 39, INT, 2,						\
		{CHAR_P, MODE_T, VOID, VOID, VOID, VOID}},		\
	{"rmdir", 40, INT, 1,						\
		{CHAR_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"dup", 41, INT, 1,						\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"pipe", 42, INT, 1,						\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"times", 43, CLOCK_T, 1,					\
		{STRUCT_TMS_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"prof", 44, VOID, 0,						\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"brk", 45, INT, 1,						\
		{VOID_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"setgid", 46, INT, 1,						\
		{GID_T, VOID, VOID, VOID, VOID, VOID}},			\
	{"getgid", 47, GID_T, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"signal", 48, SIGHANDLER_T, 2,					\
		{INT, SIGHANDLER_T, VOID, VOID, VOID, VOID}},		\
	{"geteuid", 49, UID_T, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"getegid", 50, GID_T, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"acct", 51, INT, 1,						\
		{CHAR_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"umount2", 52, INT, 2,						\
		{CHAR_P, INT, VOID, VOID, VOID, VOID}},			\
	{"lock", 53, VOID, 0,						\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"ioctl", 54, INT, 3,						\
		{INT, INT, VARARGS, VOID, VOID, VOID}},			\
	{"fcntl", 55, INT, 3,						\
		{INT, INT, VARARGS, VOID, VOID, VOID}},			\
	{"mpx", 56, VOID, 0,						\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"setpgid", 57, INT, 2,						\
		{PID_T, PID_T, VOID, VOID, VOID, VOID}},		\
	{"ulimit", 58, VOID, 0,						\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"oldolduname", 59, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"umask", 60, MODE_T, 1,					\
		{MODE_T, VOID, VOID, VOID, VOID, VOID}},		\
	{"chroot", 61, INT, 1,						\
		{CHAR_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"ustat", 62, INT, 2,						\
		{DEV_T, STRUCT_USTAT_P, VOID, VOID, VOID, VOID}},	\
	{"dup2", 63, INT, 2,						\
		{INT, INT, VOID, VOID, VOID, VOID}},			\
	{"getppid", 64, PID_T, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"getpgrp", 65, PID_T, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"setsid", 66, PID_T, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"sigaction", 67, INT, 3,					\
		{INT, STRUCT_SIGACTION_P, STRUCT_SIGACTION_P, VOID,	\
			VOID, VOID}},					\
	{"sgetmask", 68, LONG, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"ssetmask", 69, LONG, 1,					\
		{LONG, VOID, VOID, VOID, VOID, VOID}},			\
	{"setreuid", 70, INT, 2,					\
		{UID_T, UID_T, VOID, VOID, VOID, VOID}},		\
	{"setregid", 71, INT, 2,					\
		{GID_T, GID_T, VOID, VOID, VOID, VOID}},		\
	{"sigsuspend", 72, INT, 1,					\
		{SIGSET_T_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"sigpending", 73, INT, 1,					\
		{SIGSET_T_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"sethostname", 74, INT, 2,					\
		{CHAR_P, SIZE_T, VOID, VOID, VOID, VOID}},		\
	{"setrlimit", 75, INT, 2,					\
		{INT, STRUCT_RLIMIT_P, VOID, VOID, VOID, VOID}},	\
	{"getrlimit", 76, INT, 2,					\
		{INT, STRUCT_RLIMIT_P, VOID, VOID, VOID, VOID}},	\
	{"getrusage", 77, INT, 2,					\
		{INT, STRUCT_RUSAGE_P, VOID, VOID, VOID, VOID}},	\
	{"gettimeofday", 78, INT, 2,					\
		{STRUCT_TIMEVAL_P, STRUCT_TIMEZONE_P, VOID, VOID, VOID,	\
			VOID}},						\
	{"settimeofday", 79, INT, 2,					\
		{STRUCT_TIMEVAL_P, STRUCT_TIMEZONE_P, VOID, VOID, VOID, \
			VOID}},						\
	{"getgroups", 80, INT, 2,					\
		{INT, GID_T, VOID, VOID, VOID, VOID}},			\
	{"setgroups", 81, INT, 2,					\
		{SIZE_T, GID_T_P, VOID, VOID, VOID, VOID}},		\
	{"select", 82, INT, 5,						\
		{INT, FD_SET_P, FD_SET_P, FD_SET_P, STRUCT_TIMEVAL_P,	\
			VOID}},						\
	{"symlink", 83, INT, 2,						\
		{CHAR_P, CHAR_P, VOID, VOID, VOID, VOID}},		\
	{"oldlstat", 84, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"readlink", 85, SSIZE_T, 3,					\
		{CHAR_P, CHAR_P, SIZE_T, VOID, VOID, VOID}},		\
	{"uselib", 86, INT, 1,						\
		{CHAR_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"swapon", 87, INT, 2,						\
		{CHAR_P, INT, VOID, VOID, VOID, VOID}},			\
	{"reboot", 88, INT, 4,						\
		{INT, INT, INT, VOID_P, VOID, VOID}},			\
	{"readdir", 89, INT, 3,						\
		{UNSIGNED_INT, STRUCT_OLD_LINUX_DIRENT_P, UNSIGNED_INT,	\
			VOID, VOID, VOID}},				\
	{"mmap", 90, VOID_P, 6,						\
		{VOID_P, SIZE_T, INT, INT, INT, OFF_T}},		\
	{"munmap", 91, INT, 2,						\
		{VOID_P, SIZE_T, VOID, VOID, VOID, VOID}},		\
	{"truncate", 92, INT, 2,					\
		{CHAR_P, OFF_T, VOID, VOID, VOID, VOID}},		\
	{"ftruncate", 93, INT, 2,					\
		{INT, OFF_T, VOID, VOID, VOID, VOID}},			\
	{"fchmod", 94, INT, 2,						\
		{INT, MODE_T, VOID, VOID, VOID, VOID}},			\
	{"fchown", 95, INT, 3,						\
		{INT, UID_T, GID_T, VOID, VOID, VOID}},			\
	{"getpriority", 96, INT, 2,					\
		{INT, INT, VOID, VOID, VOID, VOID}},			\
	{"setpriority", 97, INT, 3,					\
		{INT, INT, INT, VOID, VOID, VOID}},			\
	{"profil", 98, VOID, 0,						\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"statfs", 99, INT, 2,						\
		{CHAR_P, STRUCT_STATFS_P, VOID, VOID, VOID, VOID}},	\
	{"fstatfs", 100, INT, 2,					\
		{INT, STRUCT_STATFS_P, VOID, VOID, VOID, VOID}},	\
	{"ioperm", 101, INT, 3,						\
		{UNSIGNED_LONG, UNSIGNED_LONG, INT, VOID, VOID, VOID}},	\
	{"socketcall", 102, INT, 2,					\
		{INT, UNSIGNED_LONG_P, VOID, VOID, VOID, VOID}},	\
	{"syslog", 103, INT, 3,						\
		{INT, CHAR_P, INT, VOID, VOID, VOID}},			\
	{"setitimer", 104, INT, 3,					\
		{INT, STRUCT_ITIMERVAL_P, STRUCT_ITIMERVAL_P, VOID,	\
			VOID, VOID}},					\
	{"getitimer", 105, INT, 2,					\
		{INT, STRUCT_ITIMERVAL_P, VOID, VOID, VOID, VOID}},	\
	{"stat", 106, INT, 2,						\
		{CHAR_P, STRUCT_STAT_P, VOID, VOID, VOID, VOID}},	\
	{"lstat", 107, INT, 2,						\
		{CHAR_P, STRUCT_STAT_P, VOID, VOID, VOID, VOID}},	\
	{"fstat", 108, INT, 2,						\
		{INT, STRUCT_STAT_P, VOID, VOID, VOID, VOID}},		\
	{"olduname", 109, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"iopl", 110, INT, 1,						\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"vhangup", 111, INT, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"idle", 112, INT, 0,						\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"vm86old", 113, INT, 1,					\
		{STRUCT_VM86_STRUCT_P, VOID, VOID, VOID, VOID, VOID}},	\
	{"wait4", 114, PID_T, 4,					\
		{PID_T, INT_P, INT, STRUCT_RUSAGE_P, VOID, VOID}},	\
	{"swapoff", 115, INT, 1,					\
		{CHAR_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"sysinfo", 116, INT, 1,					\
		{STRUCT_SYSINFO_P, VOID, VOID, VOID, VOID, VOID}},	\
	{"ipc", 117, INT, 6,						\
		{UNSIGNED_INT, INT, INT, INT, VOID_P, LONG}},		\
	{"fsync", 118, INT, 1,						\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"sigreturn", 119, INT, 1,					\
		{UNSIGNED_LONG, VOID, VOID, VOID, VOID, VOID}},		\
	{"clone", 120, INT, 5,						\
		{INT, VOID_P, INT, VOID_P, VARARGS, VOID}},		\
	{"setdomainname", 121, INT, 2,					\
		{CHAR_P, SIZE_T, VOID, VOID, VOID, VOID}},		\
	{"uname", 122, INT, 1,						\
		{STRUCT_UTSNAME_P, VOID, VOID, VOID, VOID, VOID}},	\
	{"modify_ldt", 123, INT, 3,					\
		{INT, VOID_P, UNSIGNED_LONG, VOID, VOID, VOID}},	\
	{"adjtimex", 124, INT, 1,					\
		{STRUCT_TIMEX_P, VOID, VOID, VOID, VOID, VOID}},	\
	{"mprotect", 125, INT, 3,					\
		{VOID_P, SIZE_T, INT, VOID, VOID, VOID}},		\
	{"sigprocmask", 126, INT, 3,					\
		{INT, SIGSET_T_P, SIGSET_T_P, VOID, VOID, VOID}},	\
	{"create_module", 127, CADDR_T, 2,				\
		{CHAR_P, SIZE_T, VOID, VOID, VOID, VOID}},		\
	{"init_module", 128, INT, 3,					\
		{VOID_P, UNSIGNED_LONG, CHAR_P, VOID, VOID, VOID}},	\
	{"delete_module", 129, INT, 2,					\
		{CHAR_P, INT, VOID, VOID, VOID, VOID}},			\
	{"get_kernel_syms", 130, INT, 1,				\
		{STRUCT_KERNEL_SYM_P, VOID, VOID, VOID, VOID, VOID}},	\
	{"quotactl", 131, INT, 4,					\
		{INT, CHAR_P, INT, CADDR_T, VOID, VOID}},		\
	{"getpgid", 132, PID_T, 1,					\
		{PID_T, VOID, VOID, VOID, VOID, VOID}},			\
	{"fchdir", 133, INT, 1,						\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"bdflush", 134, INT, 2,					\
		{INT, LONG_P, VOID, VOID, VOID, VOID}},			\
	{"sysfs", 135, INT, 2,						\
		{INT, CHAR_P, VOID, VOID, VOID, VOID}},			\
	{"personality", 136, INT, 1,					\
		{UNSIGNED_LONG, VOID, VOID, VOID, VOID, VOID}},		\
	{"afs_syscall", 137, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"setfsuid", 138, INT, 1,					\
		{UID_T, VOID, VOID, VOID, VOID, VOID}},			\
	{"setfsgid", 139, INT, 1,					\
		{UID_T, VOID, VOID, VOID, VOID, VOID}},			\
	{"_llseek", 140, INT, 5,					\
		{UNSIGNED_INT, UNSIGNED_LONG, UNSIGNED_LONG, LOFF_T_P,	\
			UNSIGNED_INT, VOID}},				\
	{"getdents", 141, INT, 3,					\
		{UNSIGNED_INT, STRUCT_LINUX_DIRENT_P, UNSIGNED_INT,	\
			VOID, VOID, VOID}},				\
	{"_newselect", 142, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"flock", 143, INT, 2,						\
		{INT, INT, VOID, VOID, VOID, VOID}},			\
	{"msync", 144, INT, 3,						\
		{VOID_P, SIZE_T, INT, VOID, VOID, VOID}},		\
	{"readv", 145, SSIZE_T, 3,					\
		{INT, STRUCT_IOVEC_P, INT, VOID, VOID, VOID}},		\
	{"writev", 146, SSIZE_T, 3,					\
		{INT, STRUCT_IOVEC_P, INT, VOID, VOID, VOID}},		\
	{"getsid", 147, PID_T, 1,					\
		{PID_T, VOID, VOID, VOID, VOID, VOID}},			\
	{"fdatasync", 148, INT, 1,					\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"_sysctl", 149, INT, 1,					\
		{STRUCT___SYSCTL_ARGS_P, VOID, VOID, VOID, VOID,	\
			VOID}},						\
	{"mlock", 150, INT, 2,						\
		{VOID_P, SIZE_T, VOID, VOID, VOID, VOID}},		\
	{"munlock", 151, INT, 2,					\
		{VOID_P, SIZE_T, VOID, VOID, VOID, VOID}},		\
	{"mlockall", 152, INT, 1,					\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"munlockall", 153, INT, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"sched_setparam", 154, INT, 2,					\
		{PID_T, STRUCT_SCHED_PARAM_P, VOID, VOID, VOID, VOID}},	\
	{"sched_getparam", 155, INT, 2,					\
		{PID_T, STRUCT_SCHED_PARAM_P, VOID, VOID, VOID, VOID}},	\
	{"sched_setscheduler", 156, INT, 3,				\
		{PID_T, INT, STRUCT_SCHED_PARAM_P, VOID, VOID, VOID}},	\
	{"sched_getscheduler", 157, INT, 1,				\
		{PID_T, VOID, VOID, VOID, VOID, VOID}},			\
	{"sched_yield", 158, INT, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"sched_get_priority_max", 159, INT, 1,				\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"sched_get_priority_min", 160, INT, 1,				\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"sched_rr_get_interval", 161, INT, 2,				\
		{PID_T, STRUCT_TIMESPEC_P, VOID, VOID, VOID, VOID}},	\
	{"nanosleep", 162, INT, 2,					\
		{STRUCT_TIMESPEC_P, STRUCT_TIMESPEC_P, VOID, VOID,	\
			VOID, VOID}},					\
	{"mremap", 163, VOID_P, 5,					\
		{VOID_P, SIZE_T, SIZE_T, INT, VARARGS, VOID}},		\
	{"setresuid", 164, INT, 3,					\
		{UID_T, UID_T, UID_T, VOID, VOID, VOID}},		\
	{"getresuid", 165, INT, 3,					\
		{UID_T_P, UID_T_P, UID_T_P, VOID, VOID, VOID}},		\
	{"vm86", 166, INT, 1,						\
		{STRUCT_VM86_STRUCT_P, VOID, VOID, VOID, VOID, VOID}},	\
	{"query_module", 167, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"poll", 168, INT, 3,						\
		{STRUCT_POLLFD_P, NFDS_T, INT, VOID, VOID, VOID}},	\
	{"nfsservctl", 169, LONG, 3,					\
		{INT, STRUCT_NFSCTL_ARG_P, UNION_NFSCTL_RES_P, VOID,	\
			VOID, VOID}},					\
	{"setresgid", 170, INT, 3,					\
		{GID_T, GID_T, GID_T, VOID, VOID, VOID}},		\
	{"getresgid", 171, INT, 3,					\
		{GID_T_P, GID_T_P, GID_T_P, VOID, VOID, VOID}},		\
	{"prctl", 172, INT, 5,						\
		{INT, UNSIGNED_LONG, UNSIGNED_LONG, UNSIGNED_LONG,	\
			UNSIGNED_LONG, VOID}},				\
	{"rt_sigreturn", 173, INT, 1,					\
		{UNSIGNED_LONG, VOID, VOID, VOID, VOID, VOID}},		\
	{"rt_sigaction", 174, INT, 3,					\
		{INT, STRUCT_SIGACTION_P, STRUCT_SIGACTION_P, VOID,	\
			VOID, VOID}},					\
	{"rt_sigprocmask", 175, INT, 3,					\
		{INT, SIGSET_T_P, SIGSET_T_P, VOID, VOID, VOID}},	\
	{"rt_sigpending", 176, INT, 1,					\
		{SIGSET_T_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"rt_sigtimedwait", 177, INT, 3,				\
		{SIGSET_T_P, SIGINFO_T_P, STRUCT_TIMESPEC_P, VOID,	\
			VOID, VOID}},					\
	{"rt_sigqueueinfo", 178, INT, 3,				\
		{PID_T, INT, SIGINFO_T_P, VOID, VOID, VOID}},		\
	{"rt_sigsuspend", 179, INT, 1,					\
		{SIGSET_T_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"pread64", 180, SSIZE_T, 4,					\
		{INT, VOID_P, SIZE_T, OFF_T, VOID, VOID}},		\
	{"pwrite64", 181, SSIZE_T, 4,					\
		{INT, VOID_P, SIZE_T, OFF_T, VOID, VOID}},		\
	{"chown", 182, INT, 3,						\
		{CHAR_P, UID_T, GID_T, VOID, VOID, VOID}},		\
	{"getcwd", 183, CHAR_P, 2,					\
		{CHAR_P, SIZE_T, VOID, VOID, VOID, VOID}},		\
	{"capget", 184, INT, 2,						\
		{CAP_USER_HEADER_T, CAP_USER_DATA_T, VOID, VOID, VOID,	\
			VOID}},						\
	{"capset", 185, INT, 2,						\
		{CAP_USER_HEADER_T, CAP_USER_DATA_T, VOID, VOID, VOID,	\
			VOID}},						\
	{"sigaltstack", 186, INT, 2,					\
		{STACK_T_P, STACK_T_P, VOID, VOID, VOID, VOID}},	\
	{"sendfile", 187, SSIZE_T, 4,					\
		{INT, INT, OFF_T_P, SIZE_T, VOID, VOID}},		\
	{"getpmsg", 188, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"putpmsg", 189, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"vfork", 190, PID_T, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"ugetrlimit", 191, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"mmap2", 192, VOID_P, 6,					\
		{VOID_P, SIZE_T, INT, INT, INT, OFF_T}},		\
	{"truncate64", 193, INT, 2,					\
		{CHAR_P, OFF_T, VOID, VOID, VOID, VOID}},		\
	{"ftruncate64", 194, INT, 2,					\
		{INT, OFF_T, VOID, VOID, VOID, VOID}},			\
	{"stat64", 195, INT, 2,						\
		{CHAR_P, STRUCT_STAT_P, VOID, VOID, VOID, VOID}},	\
	{"lstat64", 196, INT, 2,					\
		{CHAR_P, STRUCT_STAT_P, VOID, VOID, VOID, VOID}},	\
	{"fstat64", 197, INT, 2,					\
		{INT, STRUCT_STAT_P, VOID, VOID, VOID, VOID}},		\
	{"lchown32", 198, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"getuid32", 199, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"getgid32", 200, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"geteuid32", 201, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"getegid32", 202, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"setreuid32", 203, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"setregid32", 204, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"getgroups32", 205, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"setgroups32", 206, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"fchown32", 207, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"setresuid32", 208, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"getresuid32", 209, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"setresgid32", 210, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"getresgid32", 211, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"chown32", 212, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"setuid32", 213, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"setgid32", 214, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"setfsuid32", 215, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"setfsgid32", 216, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"pivot_root", 217, INT, 2,					\
		{CHAR_P, CHAR_P, VOID, VOID, VOID, VOID}},		\
	{"mincore", 218, INT, 3,					\
		{VOID_P, SIZE_T, UNSIGNED_CHAR_P, VOID, VOID, VOID}},	\
	{"madvise", 219, INT, 3,					\
		{VOID_P, SIZE_T, INT, VOID, VOID, VOID}},		\
	{"getdents64", 220, INT, 3,					\
		{UNSIGNED_INT, STRUCT_LINUX_DIRENT_P, UNSIGNED_INT,	\
			VOID, VOID, VOID}},				\
	{"fcntl64", 221, INT, 3,					\
		{INT, INT, VARARGS, VOID, VOID, VOID}},			\
	{"gettid", 224, PID_T, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"readahead", 225, SSIZE_T, 3,					\
		{INT, OFF64_T, SIZE_T, VOID, VOID, VOID}},		\
	{"setxattr", 226, INT, 5,					\
		{CHAR_P, CHAR_P, VOID_P, SIZE_T, INT, VOID}},		\
	{"lsetxattr", 227, INT, 5,					\
		{CHAR_P, CHAR_P, VOID_P, SIZE_T, INT, VOID}},		\
	{"fsetxattr", 228, INT, 5,					\
		{INT, CHAR_P, VOID_P, SIZE_T, INT, VOID}},		\
	{"getxattr", 229, SSIZE_T, 4,					\
		{CHAR_P, CHAR_P, VOID_P, SIZE_T, VOID, VOID}},		\
	{"lgetxattr", 230, SSIZE_T, 4,					\
		{CHAR_P, CHAR_P, VOID_P, SIZE_T, VOID, VOID}},		\
	{"fgetxattr", 231, SSIZE_T, 4,					\
		{INT, CHAR_P, VOID_P, SIZE_T, VOID, VOID}},		\
	{"listxattr", 232, SSIZE_T, 3,					\
		{CHAR_P, CHAR_P, SIZE_T, VOID, VOID, VOID}},		\
	{"llistxattr", 233, SSIZE_T, 3,					\
		{CHAR_P, CHAR_P, SIZE_T, VOID, VOID, VOID}},		\
	{"flistxattr", 234, SSIZE_T, 3,					\
		{INT, CHAR_P, SIZE_T, VOID, VOID, VOID}},		\
	{"removexattr", 235, INT, 2,					\
		{CHAR_P, CHAR_P, VOID, VOID, VOID, VOID}},		\
	{"lremovexattr", 236, INT, 2,					\
		{CHAR_P, CHAR_P, VOID, VOID, VOID, VOID}},		\
	{"fremovexattr", 237, INT, 2,					\
		{INT, CHAR_P, VOID, VOID, VOID, VOID}},			\
	{"tkill", 238, INT, 2,						\
		{INT, INT, VOID, VOID, VOID, VOID}},			\
	{"sendfile64", 239, SSIZE_T, 4,					\
		{INT, INT, OFF_T_P, SIZE_T, VOID, VOID}},		\
	{"futex", 240, INT, 6,						\
		{INT_P, INT, INT, STRUCT_TIMESPEC_P, INT_P, INT}},	\
	{"sched_setaffinity", 241, INT, 3,				\
		{PID_T, SIZE_T, CPU_SET_T_P, VOID, VOID, VOID}},	\
	{"sched_getaffinity", 242, INT, 3,				\
		{PID_T, SIZE_T, CPU_SET_T_P, VOID, VOID, VOID}},	\
	{"set_thread_area", 243, INT, 1,				\
		{STRUCT_USER_DESC_P, VOID, VOID, VOID, VOID, VOID}},	\
	{"get_thread_area", 244, INT, 1,				\
		{STRUCT_USER_DESC_P, VOID, VOID, VOID, VOID, VOID}},	\
	{"io_setup", 245, INT, 2,					\
		{UNSIGNED_NR_EVENTS, AIO_CONTEXT_T_P, VOID, VOID, VOID,	\
			VOID}},						\
	{"io_destroy", 246, INT, 1,					\
		{AIO_CONTEXT_T, VOID, VOID, VOID, VOID, VOID}},		\
	{"io_getevents", 247, INT, 5,					\
		{AIO_CONTEXT_T, LONG, LONG, STRUCT_IO_EVENT_P,		\
			STRUCT_TIMESPEC_P, VOID}},			\
	{"io_submit", 248, INT, 3,					\
		{AIO_CONTEXT_T, LONG, STRUCT_IOCB_PP, VOID, VOID,	\
			VOID}},						\
	{"io_cancel", 249, INT, 3,					\
		{AIO_CONTEXT_T, STRUCT_IOCB_P, STRUCT_IO_EVENT_P, VOID,	\
			VOID, VOID}},					\
	{"fadvise64", 250, INT, 4,					\
		{INT, OFF_T, OFF_T, INT, VOID, VOID}},			\
	{"exit_group", 252, VOID, 1,					\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"lookup_dcookie", 253, INT, 3,					\
		{U64, CHAR_P, SIZE_T, VOID, VOID, VOID}},		\
	{"epoll_create", 254, INT, 1,					\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"epoll_ctl", 255, INT, 4,					\
		{INT, INT, INT, STRUCT_EPOLL_EVENT_P, VOID, VOID}},	\
	{"epoll_wait", 256, INT, 4,					\
		{INT, STRUCT_EPOLL_EVENT_P, INT, INT, VOID, VOID}},	\
	{"remap_file_pages", 257, INT, 5,				\
		{VOID_P, SIZE_T, INT, SSIZE_T, INT, VOID}},		\
	{"set_tid_address", 258, LONG, 1,				\
		{INT_P, VOID, VOID, VOID, VOID, VOID}},			\
	{"timer_create", 259, INT, 3,					\
		{CLOCKID_T, STRUCT_SIGEVENT_P, TIMER_T_P, VOID, VOID,	\
			VOID}},						\
	{"timer_settime", 260, INT, 4,					\
		{TIMER_T, INT, STRUCT_ITIMERSPEC_P,			\
			STRUCT_ITIMERSPEC_P, VOID, VOID}},		\
	{"timer_gettime", 261, INT, 2,					\
		{TIMER_T, STRUCT_ITIMERSPEC_P, VOID, VOID, VOID,	\
			VOID}},						\
	{"timer_getoverrun", 262, INT, 1,				\
		{TIMER_T, VOID, VOID, VOID, VOID, VOID}},		\
	{"timer_delete", 263, INT, 1,					\
		{TIMER_T, VOID, VOID, VOID, VOID, VOID}},		\
	{"clock_settime", 264, INT, 2,					\
		{CLOCKID_T, STRUCT_TIMESPEC_P, VOID, VOID, VOID,	\
			VOID}},						\
	{"clock_gettime", 265, INT, 2,					\
		{CLOCKID_T, STRUCT_TIMESPEC_P, VOID, VOID, VOID,	\
			VOID}},						\
	{"clock_getres", 266, INT, 2,					\
		{CLOCKID_T, STRUCT_TIMESPEC_P, VOID, VOID, VOID,	\
			VOID}},						\
	{"clock_nanosleep", 267, INT, 4,				\
		{CLOCKID_T, INT, STRUCT_TIMESPEC_P, STRUCT_TIMESPEC_P,	\
			VOID, VOID}},					\
	{"statfs64", 268, INT, 2,					\
		{CHAR_P, STRUCT_STATFS_P, VOID, VOID, VOID, VOID}},	\
	{"fstatfs64", 269, INT, 2,					\
		{INT, STRUCT_STATFS_P, VOID, VOID, VOID, VOID}},	\
	{"tgkill", 270, INT, 3,						\
		{INT, INT, INT, VOID, VOID, VOID}},			\
	{"utimes", 271, INT, 2,						\
		{CHAR_P, STRUCT_TIMEVAL, VOID, VOID, VOID, VOID}},	\
	{"fadvise64_64", 272, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"vserver", 273, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"mbind", 274, INT, 6,						\
		{VOID_P, UNSIGNED_LONG, INT, UNSIGNED_LONG_P,		\
			UNSIGNED_LONG, UNSIGNED_FLAGS}},		\
	{"get_mempolicy", 275, INT, 5,					\
		{INT_P, UNSIGNED_LONG_P, UNSIGNED_LONG, UNSIGNED_LONG,	\
			UNSIGNED_LONG, VOID}},				\
	{"set_mempolicy", 276, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"mq_open", 277, MQD_T, 2,					\
		{CHAR_P, INT, VOID, VOID, VOID, VOID}},			\
	{"mq_unlink", 278, INT, 1,					\
		{CHAR_P, VOID, VOID, VOID, VOID, VOID}},		\
	{"mq_timedsend", 279, INT, 5,					\
		{MQD_T, CHAR_P, SIZE_T, UNSIGNED_MSG_PRIO,		\
			STRUCT_TIMESPEC_P, VOID}},			\
	{"mq_timedreceive", 280, SSIZE_T, 5,				\
		{MQD_T, CHAR_P, SIZE_T, UNSIGNED_PMSG_PRIO,		\
			STRUCT_TIMESPEC_P, VOID}},			\
	{"mq_notify", 281, INT, 2,					\
		{MQD_T, STRUCT_SIGEVENT_P, VOID, VOID, VOID, VOID}},	\
	{"mq_getsetattr", 282, INT, 3,					\
		{MQD_T, STRUCT_MQ_ATTR_P, STRUCT_MQ_ATTR_P, VOID, VOID,	\
			VOID}},						\
	{"kexec_load", 283, LONG, 4,					\
		{UNSIGNED_LONG, UNSIGNED_LONG, STRUCT_KEXEC_SEGMENT_P,	\
			UNSIGNED_LONG, VOID, VOID}},			\
	{"waitid", 284, INT, 4,						\
		{IDTYPE_T, ID_T, SIGINFO_T_P, INT, VOID, VOID}},	\
	{"add_key", 286, KEY_SERIAL_T, 5,				\
		{CHAR_P, CHAR_P, VOID_P, SIZE_T, KEY_SERIAL_T, VOID}},	\
	{"request_key", 287, KEY_SERIAL_T, 4,				\
		{CHAR_P, CHAR_P, CHAR_P, KEY_SERIAL_T, VOID, VOID}},	\
	{"keyctl", 288, LONG, 2,					\
		{INT, VARARGS, VOID, VOID, VOID, VOID}},		\
	{"ioprio_set", 289, INT, 3,					\
		{INT, INT, INT, VOID, VOID, VOID}},			\
	{"ioprio_get", 290, INT, 2,					\
		{INT, INT, VOID, VOID, VOID, VOID}},			\
	{"inotify_init", 291, INT, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"inotify_add_watch", 292, INT, 3,				\
		{INT, CHAR_P, UINT32_T, VOID, VOID, VOID}},		\
	{"inotify_rm_watch", 293, INT, 2,				\
		{INT, INT, VOID, VOID, VOID, VOID}},			\
	{"migrate_pages", 294, LONG, 4,					\
		{INT, UNSIGNED_LONG, UNSIGNED_LONG_P, UNSIGNED_LONG_P,	\
			VOID, VOID}},					\
	{"openat", 295, INT, 3,						\
		{INT, CHAR_P, INT, VOID, VOID, VOID}},			\
	{"mkdirat", 296, INT, 3,					\
		{INT, CHAR_P, MODE_T, VOID, VOID, VOID}},		\
	{"mknodat", 297, INT, 4,					\
		{INT, CHAR_P, MODE_T, DEV_T, VOID, VOID}},		\
	{"fchownat", 298, INT, 5,					\
		{INT, CHAR_P, UID_T, GID_T, INT, VOID}},		\
	{"futimesat", 299, INT, 3,					\
		{INT, CHAR_P, STRUCT_TIMEVAL, VOID, VOID, VOID}},	\
	{"fstatat64", 300, INT, 4,					\
		{INT, CHAR_P, STRUCT_STAT_P, INT, VOID, VOID}},		\
	{"unlinkat", 301, INT, 3,					\
		{INT, CHAR_P, INT, VOID, VOID, VOID}},			\
	{"renameat", 302, INT, 4,					\
		{INT, CHAR_P, INT, CHAR_P, VOID, VOID}},		\
	{"linkat", 303, INT, 5,						\
		{INT, CHAR_P, INT, CHAR_P, INT, VOID}},			\
	{"symlinkat", 304, INT, 3,					\
		{CHAR_P, INT, CHAR_P, VOID, VOID, VOID}},		\
	{"readlinkat", 305, INT, 4,					\
		{INT, CHAR_P, CHAR_P, SIZE_T, VOID, VOID}},		\
	{"fchmodat", 306, INT, 4,					\
		{INT, CHAR_P, MODE_T, INT, VOID, VOID}},		\
	{"faccessat", 307, INT, 4,					\
		{INT, CHAR_P, INT, INT, VOID, VOID}},			\
	{"pselect6", 308, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"ppoll", 309, INT, 4,						\
		{STRUCT_POLLFD_P, NFDS_T, STRUCT_TIMESPEC_P,		\
			SIGSET_T_P, VOID, VOID}},			\
	{"unshare", 310, INT, 1,					\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"set_robust_list", 311, LONG, 2,				\
		{STRUCT_ROBUST_LIST_HEAD_P, SIZE_T, VOID, VOID, VOID,	\
			VOID}},						\
	{"get_robust_list", 312, LONG, 3,				\
		{INT, STRUCT_ROBUST_LIST_HEAD_PP, SIZE_T_P, VOID, VOID,	\
			VOID}},						\
	{"splice", 313, SSIZE_T, 6,					\
		{INT, LOFF_T_P, INT, LOFF_T_P, SIZE_T, UNSIGNED_INT}},	\
	{"sync_file_range", 314, INT, 4,				\
		{INT, OFF64_T, OFF64_T, UNSIGNED_INT, VOID, VOID}},	\
	{"tee", 315, SSIZE_T, 4,					\
		{INT, INT, SIZE_T, UNSIGNED_INT, VOID, VOID}},		\
	{"vmsplice", 316, SSIZE_T, 4,					\
		{INT, STRUCT_IOVEC_P, UNSIGNED_LONG, UNSIGNED_INT,	\
			VOID, VOID}},					\
	{"move_pages", 317, LONG, 6,					\
		{INT, UNSIGNED_LONG, VOID_PP, INT_P, INT_P, INT}},	\
	{"getcpu", 318, INT, 3,						\
		{UNSIGNED_PCPU, UNSIGNED_PNODE, STRUCT_GETCPU_CACHE_P,	\
			VOID, VOID, VOID}},				\
	{"epoll_pwait", 319, INT, 5,					\
		{INT, STRUCT_EPOLL_EVENT_P, INT, INT, SIGSET_T_P,	\
			VOID}},						\
	{"utimensat", 320, INT, 4,					\
		{INT, CHAR_P, STRUCT_TIMESPEC, INT, VOID, VOID}},	\
	{"signalfd", 321, INT, 3,					\
		{INT, SIGSET_T_P, INT, VOID, VOID, VOID}},		\
	{"timerfd_create", 322, INT, 2,					\
		{INT, INT, VOID, VOID, VOID, VOID}},			\
	{"eventfd", 323, INT, 2,					\
		{UNSIGNED_INT, INT, VOID, VOID, VOID, VOID}},		\
	{"fallocate", 324, INT, 4,					\
		{INT, INT, OFF_T, OFF_T, VOID, VOID}},			\
	{"timerfd_settime", 325, INT, 4,				\
		{INT, INT, STRUCT_ITIMERSPEC_P, STRUCT_ITIMERSPEC_P,	\
			VOID, VOID}},					\
	{"timerfd_gettime", 326, INT, 2,				\
		{INT, STRUCT_ITIMERSPEC_P, VOID, VOID, VOID, VOID}},	\
	{"signalfd4", 327, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"eventfd2", 328, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"epoll_create1", 329, INT, 1,					\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"dup3", 330, INT, 3,						\
		{INT, INT, INT, VOID, VOID, VOID}},			\
	{"pipe2", 331, INT, 2,						\
		{INT, INT, VOID, VOID, VOID, VOID}},			\
	{"inotify_init1", 332, INT, 1,					\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"preadv", 333, SSIZE_T, 4,					\
		{INT, STRUCT_IOVEC_P, INT, OFF_T, VOID, VOID}},		\
	{"pwritev", 334, SSIZE_T, 4,					\
		{INT, STRUCT_IOVEC_P, INT, OFF_T, VOID, VOID}},		\
	{"rt_tgsigqueueinfo", 335, INT, 4,				\
		{PID_T, PID_T, INT, SIGINFO_T_P, VOID, VOID}},		\
	{"perf_event_open", 336, INT, 5,				\
		{STRUCT_PERF_EVENT_ATTR_P, PID_T, INT, INT,		\
			UNSIGNED_LONG, VOID}},				\
	{"recvmmsg", 337, INT, 5,					\
		{INT, STRUCT_MMSGHDR_P, UNSIGNED_INT, UNSIGNED_INT,	\
			STRUCT_TIMESPEC_P, VOID}},			\
	{"fanotify_init", 338, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"fanotify_mark", 339, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"prlimit64", 340, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"name_to_handle_at", 341, VOID, 0,				\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"open_by_handle_at", 342, VOID, 0,				\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"clock_adjtime", 343, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"syncfs", 344, INT, 1,						\
		{INT, VOID, VOID, VOID, VOID, VOID}},			\
	{"sendmmsg", 345, INT, 4,					\
		{INT, STRUCT_MMSGHDR_P, UNSIGNED_INT, UNSIGNED_INT,	\
			VOID, VOID}},					\
	{"setns", 346, INT, 2,						\
		{INT, INT, VOID, VOID, VOID, VOID}},			\
	{"process_vm_readv", 347, SSIZE_T, 6,				\
		{PID_T, STRUCT_IOVEC_P, UNSIGNED_LONG, STRUCT_IOVEC_P,	\
			UNSIGNED_LONG, UNSIGNED_LONG}},			\
	{"process_vm_writev", 348, SSIZE_T, 6,				\
		{PID_T, STRUCT_IOVEC_P, UNSIGNED_LONG, STRUCT_IOVEC_P,	\
			UNSIGNED_LONG, UNSIGNED_LONG}},			\
	{"kcmp", 349, INT, 5,						\
		{PID_T, PID_T, INT, UNSIGNED_LONG, UNSIGNED_LONG,	\
			VOID}},						\
	{"finit_module", 350, INT, 3,					\
		{INT, CHAR_P, INT, VOID, VOID, VOID}},			\
	{"sched_setattr", 351, INT, 3,					\
		{PID_T, STRUCT_SCHED_ATTR_P, UNSIGNED_INT, VOID, VOID,	\
			VOID}},						\
	{"sched_getattr", 352, INT, 3,					\
		{PID_T, STRUCT_SCHED_ATTR_P, UNSIGNED_INT, VOID, VOID,	\
			VOID}},						\
	{"renameat2", 353, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}},			\
	{"seccomp", 354, VOID, 0,					\
		{VOID, VOID, VOID, VOID, VOID, VOID}}			\
}

#endif

typedef syscall_t const
	syscall_table_t[SYSCALL_TABLE_SIZE];
typedef size_t const
	param_reg_offset_table_t[PARAM_REG_OFFSET_TABLE_SIZE];

syscall_table_t *syscall_table(void);
param_reg_offset_table_t *param_reg_offset_table(void);

#endif /* _SYSCALLS_H_ */
