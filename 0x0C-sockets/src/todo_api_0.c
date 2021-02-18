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
	char *method = strtok(request, SPACE);
	char *path = strtok(NULL, SPACE);
	char *version = strtok(NULL, SPACE);

	printf("Method: %s\n", method);
	printf("Path: %s\n", path);
	printf("Version: %s\n", version);
	return (strdup(HTTP_200));
}
