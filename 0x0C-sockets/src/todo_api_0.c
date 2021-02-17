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
	char *method = strtok(request, SPACE);
	char *path = strtok(NULL, SPACE);
	char *version = strtok(NULL, SPACE);

	printf("Method: %s\n", method);
	printf("Path: %s\n", path);
	printf("Version: %s\n", version);
	return (strdup(HTTP_200));
}
