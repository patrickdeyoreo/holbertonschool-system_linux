#ifndef _SERVER_H_
#define _SERVER_H_

#include <stdlib.h>

#include "dict.h"

#define PORT 8080

#define PATH_TODOS "/todos"

#define BACKLOG (1 << 4)
#define BUF_SZ (1 << 12)
#define REQUEST_BUF_SZ (1 << 14)

/**
 * struct http_request_s - HTTP request structure
 *
 * @method: HTTP method
 * @path: resource path
 * @version: HTTP version
 * @params: URL parameters
 * @headers: request headers
 * @body: request body
 */
typedef struct http_request_s
{
	char *method;
	char *path;
	char *version;
	dict_t *params;
	dict_t *headers;
	char *body;
} http_request_t;

typedef char *(*request_handler_t)(http_request_t *);

int start_server(unsigned short int port);
int accept_connections(int server_sd);
ssize_t recv_request(int client_sd, char *request_buf, size_t request_buf_sz);
ssize_t send_response(int client_sd, const char *response);

request_handler_t *api_endpoint(const char *path, const char *method);

char *parse_request(char *request);
char *parse_post_request(char *body, size_t content_length);
char *parse_get_request();

#endif /* _SERVER_H_ */
