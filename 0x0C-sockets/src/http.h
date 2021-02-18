#ifndef _HTTP_H_
#define _HTTP_H_

#include "dict.h"
#include "util.h"

#define HTTP_GET "GET"
#define HTTP_POST "POST"
#define HTTP_PUT "PUT"
#define HTTP_DELETE "DELETE"

#define HTTP_200_NOCRLF "HTTP/1.1 200 OK"
#define HTTP_200 (HTTP_200_NOCRLF CRLF CRLF)

#define HTTP_201_NOCRLF "HTTP/1.1 201 Created"
#define HTTP_201 (HTTP_201_NOCRLF CRLF CRLF)

#define HTTP_204_NOCRLF "HTTP/1.1 204 No Content"
#define HTTP_204 (HTTP_204_NOCRLF CRLF CRLF)

#define HTTP_400_NOCRLF "HTTP/1.1 400 Bad Request"
#define HTTP_400 (HTTP_400_NOCRLF CRLF CRLF)

#define HTTP_404_NOCRLF "HTTP/1.1 404 Not Found"
#define HTTP_404 (HTTP_404_NOCRLF CRLF CRLF)

#define HTTP_411_NOCRLF "HTTP/1.1 411 Length Required"
#define HTTP_411 (HTTP_411_NOCRLF CRLF CRLF)

#define HTTP_422_NOCRLF "HTTP/1.1 422 Unprocessable Entity"
#define HTTP_422 (HTTP_422_NOCRLF CRLF CRLF)

#define CONTENT_LENGTH "Content-Length"
#define CONTENT_TYPE "Content-Type"

#define CONTENT_TYPE_JSON "application/json"
#define CONTENT_TYPE_X_WWW_FORM_URLENCODED "application/x-www-form-urlencoded"

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

http_request_t *http_request_create(char *request);
void http_request_delete(http_request_t *http_request);

#endif /* _HTTP_H_ */
