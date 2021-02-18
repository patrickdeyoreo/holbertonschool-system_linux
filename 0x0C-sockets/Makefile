CC = gcc-4.8
CFLAGS = -Wall -Werror -Wextra -pedantic
CTAGS = ctags
TAGS = .tags
RM = rm -f

SRC =  src/api.c src/dict.c src/dict_item.c src/hash.c src/http.c src/server.c src/util.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean distclean tags todo_api_0 todo_api_1 todo_api_2 todo_api_3 todo_api_4 todo_api_5 todo_api_6 todo_api_7

all: todo_api_0 todo_api_1 todo_api_2 todo_api_3 todo_api_4 todo_api_5 todo_api_6 todo_api_7

clean:
	$(RM) $(OBJ)
	$(RM) todo_api_0 todo_api_1 todo_api_2 todo_api_3 todo_api_4 todo_api_5 todo_api_6 todo_api_7

distclean: clean
	$(RM) $(TAGS)

tags:
	$(CTAGS) -f $(TAGS) -R

todo_api_0: src/todo_api_0.c $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

todo_api_1: src/todo_api_1.c $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

todo_api_2: src/todo_api_2.c $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

todo_api_3: src/todo_api_3.c $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

todo_api_4: src/todo_api_4.c $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

todo_api_5: src/todo_api_5.c $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

todo_api_6: src/todo_api_6.c $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

todo_api_7: src/todo_api_7.c $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
