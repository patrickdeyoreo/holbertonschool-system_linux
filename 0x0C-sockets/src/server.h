#ifndef _SERVER_H_
#define _SERVER_H_

#include <stdlib.h>

#include "http.h"

#define PORT 8080

#define BACKLOG (1 << 4)
#define REQUEST_BUF_SZ (1 << 14)

int start_server(unsigned short int port);
int accept_connections(int server_sd);
ssize_t recv_request(int client_sd, char *request_buf, size_t request_buf_sz);
ssize_t send_response(int client_sd, const char *response);
char *handle_request(char *request);

#endif /* _SERVER_H_ */
