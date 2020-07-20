#include "list.h"

/**
 * list_del - delete a list
 * @head: the address of a pointer to the front of a list
 */
void list_del(list_node_t **head)
{
	if (head && *head)
	{
		list_del(&(*head)->next);
		free(*head);
		*head = NULL;
	}
}

/**
 * list_len - get the length of a list
 * @head: a pointer to the front of a list
 *
 * Return: the length of the list
 */
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

/**
 * list_map_from_array - map elements of an array to a linked list
 * @base: the array to sort
 * @nmemb: the number of items
 * @size: the size of each item
 *
 * Return: a pointer to the first node of the resulting list
 */
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

/**
 * list_map_to_array - map elements of a linked list to an array
 * @head: a pointer to the front of a list
 *
 * Return: a pointer to start of the resulting array
 */
const void * const *list_map_to_array(const list_node_t *head)
{
	const void **array = NULL;
	size_t nmemb = list_len(head);

	array = calloc(nmemb, sizeof(*array));
	if (array)
	{
		for (nmemb = 0; head; head = head->next)
			array[nmemb++] = head->data;
	}
	return (array);
}
