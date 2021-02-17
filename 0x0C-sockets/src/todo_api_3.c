#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "http.h"
#include "server.h"
#include "util.h"

/**
 * main - entry point
 *
 * Return: If an error occurs, return EXIT_FAILURE.
 * Otherwise, return EXIT_SUCCESS.
 */
int main(void)
{
	return (start_server(PORT));
}

/**
 * parse_request - parse a request
 *
 * @request: pointer to the start of a null-terminated request
 *
 * Return: response to send to client
 */
char *parse_request(char *request)
{
	char *request_save = NULL;
	char *header_save = NULL;
	char *query_save = NULL;
	char *path_save = NULL;
	char *header = NULL;
	char *body = NULL;
	char *query = NULL;
	char *key = NULL;
	char *value = NULL;
	bool urlencoded = false;

	body = strstr(request, CRLF CRLF);
	if (body && strlen(body))
	{
		*body = '\0';
		body += strlen(CRLF CRLF);
	}
	strtok_r(strtok_r(request, CRLF, &request_save), BLANK, &path_save);
	printf("Path: %s\n",
		strtok_r(strtok_r(NULL, BLANK, &path_save), "?", &path_save));
	while ((header = strtok_r(NULL, CRLF, &request_save)))
	{
		key = trimwhitespace(strtok_r(header, ":", &header_save));
		value = trimwhitespace(strtok_r(NULL, CRLF, &header_save));
		if (!strcasecmp(key, CONTENT_TYPE))
			urlencoded = !strcasecmp(
				value, CONTENT_TYPE_X_WWW_FORM_URLENCODED);
	}
	if (urlencoded)
	{
		query = strtok_r(body, "&", &request_save);
		while (query)
		{
			key = strtok_r(query, "=", &query_save);
			value = strtok_r(NULL, "=", &query_save);
			printf("Body param: \"%s\" -> \"%s\"\n", key, value);
			query = strtok_r(NULL, "&", &request_save);
		}
	}
	return (strdup(HTTP_200));
}
