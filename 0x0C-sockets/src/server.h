#ifndef _SERVER_H_
#define _SERVER_H_

#include <stdlib.h>

#define PORT 8080

#define PATH_TODOS "/todos"

#define BACKLOG (1 << 4)
#define BUF_SZ (1 << 12)
#define REQUEST_BUF_SZ (1 << 14)

int start_server(unsigned short int port);
int accept_connections(int server_sd);
ssize_t recv_request(int client_sd, char *request_buf, size_t request_buf_sz);
ssize_t send_response(int client_sd, const char *response);
char *parse_request(char *request);
char *parse_post_request(char *body, size_t content_length);
char *parse_get_request();

#endif /* _SERVER_H_ */
