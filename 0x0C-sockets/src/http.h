#ifndef _HTTP_H_
#define _HTTP_H_

#define BLANK " \t"
#define CRLF "\r\n"

#define CONTENT_LENGTH \
	"Content-Length"
#define CONTENT_TYPE \
	"Content-Type"

#define JSON \
	"application/json"
#define X_WWW_FORM_URLENCODED \
	"application/x-www-form-urlencoded"

#define HTTP_RESPONSE_200_NOCRLF "HTTP/1.1 200 OK"
#define HTTP_RESPONSE_200 (HTTP_RESPONSE_200_NOCRLF CRLF CRLF)
#define HTTP_RESPONSE_400_NOCRLF "HTTP/1.1 400 Bad Request"
#define HTTP_RESPONSE_400 (HTTP_RESPONSE_400_NOCRLF CRLF CRLF)
#define HTTP_RESPONSE_404_NOCRLF "HTTP/1.1 404 Not Found"
#define HTTP_RESPONSE_404 (HTTP_RESPONSE_404_NOCRLF CRLF CRLF)
#define HTTP_RESPONSE_500_NOCRLF "HTTP/1.1 500 Internal Server Error"
#define HTTP_RESPONSE_500 (HTTP_RESPONSE_500_NOCRLF CRLF CRLF)

#endif /* _HTTP_H_ */
