#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>

/**
 * struct list_node_s - a singly linked list node
 * @data: a pointer to the data
 * @next: a pointer to the next node
 */
typedef struct list_node_s
{
	struct list_node_s *next;
	const void *data;
} list_node_t;

void list_del(list_node_t **head);
size_t list_len(const list_node_t *head);
list_node_t *list_map_from_array(const void *base, size_t nmemb, size_t size);
const void **list_map_to_array(const list_node_t *head, size_t size);

#endif /* _LIST_H_ */
