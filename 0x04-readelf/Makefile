CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
CTAGS = ctags
TAGS = .tags
RM = rm -f
.PHONY: all clean tags 0-hreadelf 1-hreadelf 2-hreadelf 100-hreadelf

all: 0-hreadelf 1-hreadelf 2-hreadelf 100-hreadelf

clean:
	$(RM) 0-hreadelf

tags:
	$(CTAGS) -f $(TAGS) -R

0-hreadelf: 0-hreadelf.c hreadelf.h
	$(CC) $(CFLAGS) $< -o $@

1-hreadelf: 1-hreadelf.c hreadelf.h
	$(CC) $(CFLAGS) $< -o $@

2-hreadelf: 2-hreadelf.c hreadelf.h
	$(CC) $(CFLAGS) $< -o $@

100-hreadelf: 100-hreadelf.c hreadelf.h
	$(CC) $(CFLAGS) $< -o $@
