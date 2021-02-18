#include <stdlib.h>
#include <string.h>

#include "dict.h"
#include "http.h"
#include "util.h"

/**
 * http_request_create - create an HTTP request
 *
 * @request: raw request to parse into an HTTP request
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the newly-created request.
 */
http_request_t *http_request_create(char *request)
{
	char *line_save = NULL;
	char *param_save = NULL;
	char *header_save = NULL;
	char *item_save = NULL;
	char *param = NULL;
	char *header = NULL;
	char *key = NULL;
	char *value = NULL;
	http_request_t *http_request = calloc(1, sizeof(*http_request));

	if (!http_request)
		return (NULL);

	http_request->body = strstr(request, CRLF CRLF);
	if (http_request->body)
	{
		*http_request->body = '\0';
		http_request->body = strdup(http_request->body + strlen(CRLF CRLF));
	}
	http_request->method = strdup(
		strtok_r(strtok_r(request, CRLF, &header_save), BLANK, &line_save));
	http_request->path = strdup(
		strtok_r(strtok_r(NULL, BLANK, &line_save), "?", &param_save));
	http_request->version = strdup(
		strtok_r(NULL, BLANK, &line_save));
	http_request->params = dict_create();
	while ((param = strtok_r(NULL, "&", &param_save)))
	{
		key = strtok_r(param, "=", &item_save);
		value = strtok_r(NULL, "", &item_save);
		dict_set(http_request->params, key, value);
	}
	http_request->headers = dict_create();
	while ((header = strtok_r(NULL, CRLF, &header_save)))
	{
		key = trimwhitespace(strtok_r(header, ":", &item_save));
		value = trimwhitespace(strtok_r(NULL, CRLF, &item_save));
		dict_set(http_request->headers, key, value);
	}
	return (http_request);
}

/**
 * http_request_delete - delete a HTTP request
 *
 * @http_request: HTTP request to delete
 */
void http_request_delete(http_request_t *http_request)
{
	if (http_request)
	{
		free(http_request->method);
		free(http_request->path);
		free(http_request->version);
		dict_delete(http_request->params);
		dict_delete(http_request->headers);
		free(http_request->body);
	}
}

