#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdlib.h>

#include "list.h"

typedef list_node_t queue_node_t;

queue_node_t *enqueue(queue_node_t **rear, const void *data);
const void *dequeue(queue_node_t **rear);

#endif /* _QUEUE_H_ */
