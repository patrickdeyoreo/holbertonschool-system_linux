CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
CTAGS = ctags
TAGS = .tags
RM = rm -f
.PHONY: all clean distclean tags strace_0

all: strace_0 strace_1 strace_2 strace_3

clean:
	$(RM) strace_0 strace_1 strace_2 strace_3

distclean: clean
	$(RM) $(TAGS)

tags:
	$(CTAGS) -f $(TAGS) -R

strace_0: src/strace_0.c src/syscalls.c
	$(CC) $(CFLAGS) $^ -o $@

strace_1: src/strace_1.c src/syscalls.c
	$(CC) $(CFLAGS) $^ -o $@

strace_2: src/strace_2.c src/syscalls.c
	$(CC) $(CFLAGS) $^ -o $@

strace_3: src/strace_3.c src/syscalls.c
	$(CC) $(CFLAGS) $^ -o $@
