CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
CTAGS = ctags
TAGS = .tags
RM = rm -f

.PHONY: all clean distclean tags todo_api_0 todo_api_1 todo_api_2 todo_api_3 todo_api_4 todo_api_5

all: todo_api_0 todo_api_1 todo_api_2 todo_api_3 todo_api_4 todo_api_5

clean:
	$(RM) todo_api_0 todo_api_1 todo_api_2 todo_api_3 todo_api_4 todo_api_5

distclean: clean
	$(RM) $(TAGS)

tags:
	$(CTAGS) -f $(TAGS) -R

todo_api_0: src/todo_api_0.c src/server.c src/util.c
	$(CC) $(CFLAGS) $^ -o $@

todo_api_1: src/todo_api_1.c src/server.c src/util.c
	$(CC) $(CFLAGS) $^ -o $@

todo_api_2: src/todo_api_2.c src/server.c src/util.c
	$(CC) $(CFLAGS) $^ -o $@

todo_api_3: src/todo_api_3.c src/server.c src/util.c
	$(CC) $(CFLAGS) $^ -o $@

todo_api_4: src/todo_api_4.c src/server.c src/util.c
	$(CC) $(CFLAGS) $^ -o $@

todo_api_5: src/todo_api_5.c src/server.c src/util.c
	$(CC) $(CFLAGS) $^ -o $@
