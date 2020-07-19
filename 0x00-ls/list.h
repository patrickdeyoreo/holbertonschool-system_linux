#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>

/**
 * struct list_s - a singly linked list node 
 * @data: a pointer to the data
 * @next: a pointer to the next node 
 */
typedef struct list_s
{
	const void *data;
	struct list_s *next;
} list_t;

list_t *array_to_list(const void *base, size_t nmemb, size_t size);
void *list_to_array(const list_t *head, size_t *nmemb, size_t *size);

#endif /* _LIST_H_ */
