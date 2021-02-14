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
	char *request_save = NULL;
	char *path_save = NULL;
	char *param_save = NULL;
	char *path = NULL;
	char *param = NULL;
	char *key = NULL;
	char *value = NULL;

	strtok_r(request_buf, DELIMS, &request_save);
	path = strtok_r(NULL, DELIMS, &request_save);

	strtok_r(path, "?", &path_save);
	printf("Path: %s\n", path);

	param = strtok_r(NULL, "&", &path_save);
	while (param)
	{
		key = strtok_r(param, "=", &param_save);
		value = strtok_r(NULL, "", &param_save);
		printf("Query: \"%s\" -> \"%s\"\n", key, value);
		param = strtok_r(NULL, "&", &path_save);
	}
}
