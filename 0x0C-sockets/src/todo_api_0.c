#include <stdio.h>
#include <string.h>

#include "server.h"

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
 * @request_buf: pointer to the start of a null-terminated request
 */
void parse_request(char *request_buf)
{
	const char *DELIMS = " \t\n\r";
	char *method = strtok(request_buf, DELIMS);
	char *path = strtok(NULL, DELIMS);
	char *version = strtok(NULL, DELIMS);

	printf("Method: %s\n", method);
	printf("Path: %s\n", path);
	printf("Version: %s\n", version);
}
