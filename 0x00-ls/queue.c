#include "queue.h"

/**
 * enqueue - add an item to the rear of a queue
 * @rear: the address of a pointer to the rear of a queue
 * @data: a pointer to the data to enqueue
 *
 * Return: a pointer to the new rear of the queue
 */
queue_node_t *enqueue(queue_node_t **rear, const void *data)
{
	queue_node_t *node = rear ? malloc(sizeof(*node)) : NULL;

	if (node)
	{
		node->data = data;
		if (*rear)
			node->next = (*rear)->next, (*rear)->next = node;
		else
			node->next = node;
		*rear = node;
	}
	return (node);
}

/**
 * dequeue - pop an item from the front of a queue
 * @rear: a pointer to the rear of a queue
 *
 * Return: a pointer to the new rear of the queue
 */
const void *dequeue(queue_node_t **rear)
{
	queue_node_t *front = rear && *rear ? (*rear)->next : NULL;
	const void *data = NULL;

	if (front)
	{
		data = front->data;

		if (front == *rear)
			(*rear) = NULL;
		else
			(*rear)->next = front->next;
		free(front);
	}
	return (data);
}
