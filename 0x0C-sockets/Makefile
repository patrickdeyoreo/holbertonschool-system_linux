CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
CTAGS = ctags
TAGS = .tags
RM = rm -f
.PHONY: all clean distclean tags todo_api_0

all: todo_api_0 todo_api_1

clean:
	$(RM) todo_api_0 todo_api_1

distclean: clean
	$(RM) $(TAGS)

tags:
	$(CTAGS) -f $(TAGS) -R

todo_api_0: src/todo_api_0.c src/server.c
	$(CC) $(CFLAGS) $^ -o $@

todo_api_1: src/todo_api_1.c src/server.c
	$(CC) $(CFLAGS) $^ -o $@
