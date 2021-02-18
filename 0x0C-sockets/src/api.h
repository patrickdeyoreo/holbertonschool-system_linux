#ifndef _API_H_
#define _API_H_

#include "http.h"
#include "todo.h"

#define BUF_SZ (1 << 12)

#define PATH_TODOS "/todos"

/**
 * struct api_endpoint_s - API endpoint structure
 *
 * @path: endpoint path
 * @method: endpoint method
 * @fn: endpoint function
 */
typedef struct api_endpoint_s
{
	const char *path;
	const char *method;
	char *(*fn)(http_request_t *);
} api_endpoint_t;

char *api_route(http_request_t *request);

char *post_todos(http_request_t *request);
char *get_todos(http_request_t *request);
char *delete_todos(http_request_t *request);

#endif /* _API_H_ */
