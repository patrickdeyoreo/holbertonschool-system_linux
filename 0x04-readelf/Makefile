CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
CTAGS = ctags
TAGS = .tags
RM = rm -f
.PHONY: all clean distclean tags 0-hreadelf 1-hreadelf 2-hreadelf 100-hreadelf

all: 0-hreadelf 1-hreadelf 2-hreadelf 100-hreadelf

clean:
	$(RM) 0-hreadelf 1-hreadelf 2-hreadelf 100-hreadelf

distclean: clean
	$(RM) $(TAGS)

tags:
	$(CTAGS) -f $(TAGS) -R

0-hreadelf: 0-hreadelf.c $(wildcard elf_file_header_*.c)
	$(CC) $(CFLAGS) $^ -o $@

1-hreadelf: 1-hreadelf.c $(wildcard elf_section_headers_*.c)
	$(CC) $(CFLAGS) $^ -o $@

2-hreadelf: 2-hreadelf.c $(wildcard elf_program_headers_*.c)
	$(CC) $(CFLAGS) $^ -o $@

100-hreadelf: 100-hreadelf.c $(wildcard elf_symbol_table_*.c)
	$(CC) $(CFLAGS) $^ -o $@
