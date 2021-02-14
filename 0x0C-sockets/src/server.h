#ifndef _SERVER_H_
#define _SERVER_H_

#define PORT 8080
#define BACKLOG (1 << 8)
#define READ_BUF_SZ (1 << 16)
#define REQUEST_BUF_SZ (1 << 16)

#define HTTP_RESPONSE_200 "HTTP/1.1 200 OK\r\n\r\n"
#define HTTP_RESPONSE_400 "HTTP/1.1 400 Bad Request\r\n\r\n"
#define HTTP_RESPONSE_404 "HTTP/1.1 404 Not Found\r\n\r\n"
#define HTTP_RESPONSE_500 "HTTP/1.1 500 Internal Server Error\r\n\r\n"


#endif /* _SERVER_H_ */
