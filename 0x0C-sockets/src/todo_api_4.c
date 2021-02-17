#include <stdio.h>
#include <string.h>

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
 * @request_buf: pointer to the start of a null-terminated request
 */
void parse_request(char *request_buf)
{
	char *request_save = NULL;
	char *header_save = NULL;
	char *header = NULL;
	char *key = NULL;
	char *value = NULL;

	strtok_r(request_buf, CRLF, &request_save);
	header = strtok_r(NULL, CRLF, &request_save);
	while (header)
	{
		key = trimwhitespace(strtok_r(header, ":", &header_save));
		value = trimwhitespace(strtok_r(NULL, CRLF, &header_save));
		printf("Header: \"%s\" -> \"%s\"\n", key, value);
		header = strtok_r(NULL, CRLF, &request_save);
	}
}
