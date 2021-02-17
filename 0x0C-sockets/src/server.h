#ifndef _SERVER_H_
#define _SERVER_H_

#include <stdlib.h>

#define PORT 8080

#define PATH_TODOS "/todos"

#define BACKLOG (1 << 4)
#define READ_BUF_SZ (1 << 16)
#define REQUEST_BUF_SZ (1 << 16)

int start_server(unsigned short int port);
int accept_connections(int server_sd);
ssize_t recv_request(int client_sd, char *request_buf, size_t request_buf_sz);
ssize_t send_response(int client_sd, const char *response);
char *parse_request(char *request);
char *post_request(char *body, size_t content_length);

#endif /* _SERVER_H_ */
