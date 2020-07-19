#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdlib.h>

#include "list.h"

typedef list_t queue_t;

queue_t *enqueue(queue_t **rear, const void *data);
const void *dequeue(queue_t **rear);

#endif /* _QUEUE_H_ */
