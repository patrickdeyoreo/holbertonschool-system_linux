#include "list.h"

void list_del(list_node_t **head)
{
	if (head && *head)
	{
		list_del(&(*head)->next);
		free(*head);
		*head = NULL;
	}
}

size_t list_len(const list_node_t *head)
{
	size_t len = 0;

	while (head)
	{
		len += 1;
		head = head->next;
	}
	return (len);
}

list_node_t *list_map_from_array(const void *base, size_t nmemb, size_t size)
{
	list_node_t *head = NULL, **tail = &head;

	if (base)
	{
		while (nmemb--)
		{
			*tail = malloc(sizeof(**tail));
			if (!*tail)
			{
				list_del(&head);
				return (NULL);
			}
			(*tail)->next = NULL;
			(*tail)->data = base;
			base = (char *) base + size;
			tail = &(*tail)->next;
		}
	}
	return (head);
}

const void **list_map_to_array(const list_node_t *head, size_t size)
{
	const void **array = NULL;
	size_t nmemb = list_len(head);

	array = calloc(nmemb, size);
	if (array)
	{
		for (nmemb = 0; head; head = head->next)
			array[nmemb++] = head->data;
	}
	return (array);
}
