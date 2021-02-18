#include <stdio.h>
#include <string.h>

#include "api.h"
#include "dict.h"
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
 * handle_request - parse a request
 *
 * @request: pointer to the start of a null-terminated request
 *
 * Return: response to send to client
 */
char *handle_request(char *request)
{
	char *request_save = NULL;
	char *header_save = NULL;
	char *header = NULL;
	char *key = NULL;
	char *value = NULL;

	strtok_r(request, CRLF, &request_save);
	header = strtok_r(NULL, CRLF, &request_save);
	while (header)
	{
		key = trimwhitespace(strtok_r(header, ":", &header_save));
		value = trimwhitespace(strtok_r(NULL, CRLF, &header_save));
		printf("Header: \"%s\" -> \"%s\"\n", key, value);
		header = strtok_r(NULL, CRLF, &request_save);
	}
	return (strdup(HTTP_200));
}
