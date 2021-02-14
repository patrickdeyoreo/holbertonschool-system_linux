#ifndef _SERVER_H_
#define _SERVER_H_

#include <stdlib.h>

#define PORT 8080
#define BACKLOG (1 << 8)
#define READ_BUF_SZ (1 << 16)
#define REQUEST_BUF_SZ (1 << 16)

#define HTTP_RESPONSE_200 "HTTP/1.1 200 OK\r\n\r\n"
#define HTTP_RESPONSE_400 "HTTP/1.1 400 Bad Request\r\n\r\n"
#define HTTP_RESPONSE_404 "HTTP/1.1 404 Not Found\r\n\r\n"
#define HTTP_RESPONSE_500 "HTTP/1.1 500 Internal Server Error\r\n\r\n"

int start_server(unsigned short int port);
int accept_connections(int server_sd);
ssize_t recv_request(int client_sd, char *request_buf, size_t request_buf_sz);
ssize_t send_response(int client_sd, const char *response);
void parse_request(char *request_buf);

#endif /* _SERVER_H_ */
