#ifndef _TODO_H_
#define _TODO_H_

#define TODO_ID "id"
#define TODO_TITLE "title"
#define TODO_DESCRIPTION "description"

/**
 * struct todo_s - TODO structure
 * @id: ID of item
 * @title: title of item
 * @description: description of item
 * @next: pointer to the next item
 */
typedef struct todo_s
{
	unsigned int id;
	char *title;
	char *description;
	struct todo_s *next;
} todo_t;

#endif /* _TODO_H_ */
