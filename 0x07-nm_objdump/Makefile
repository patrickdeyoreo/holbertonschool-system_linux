CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
CTAGS = ctags
TAGS = .tags
RM = rm -f
.PHONY: all clean distclean tags hnm hobjdump

all: hnm hobjdump

clean:
	$(RM) hnm hobjdump

distclean: clean
	$(RM) $(TAGS)

tags:
	$(CTAGS) -f $(TAGS) -R

hnm: src/hnm.c $(wildcard src/hnm/*.c) $(wildcard src/etoh/*.c) $(wildcard src/read/*.c)
	$(CC) $(CFLAGS) $^ -o $@

hobjdump: src/hobjdump.c $(wildcard src/hobjdump/*.c) $(wildcard src/etoh/*.c) $(wildcard src/read/*.c)
	$(CC) $(CFLAGS) $^ -o $@
