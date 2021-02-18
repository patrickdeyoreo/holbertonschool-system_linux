#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "api.h"
#include "dict.h"
#include "http.h"
#include "server.h"
#include "todo.h"
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
	http_request_t *http_request = http_request_create(request);
	char *response = http_request ? api_route(http_request) : NULL;

	http_request_delete(http_request);
	return (response);
}
