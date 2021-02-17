#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "http.h"
#include "server.h"
#include "todo.h"
#include "util.h"

static unsigned int id;
static todo_t *todo_head;

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
	char *path_save = NULL;
	char *header = NULL;
	char *method = NULL;
	char *path = NULL;
	char *body = NULL;
	char *key = NULL;
	char *value = NULL;
	unsigned long int content_length = 0;
	bool urlencoded = false;

	body = strstr(request, CRLF CRLF);
	if (body && strlen(body))
	{
		*body = '\0';
		body += strlen(CRLF CRLF);
	}
	method = strtok_r(strtok_r(request, CRLF, &request_save), BLANK, &path_save);
	path = strtok_r(strtok_r(NULL, BLANK, &path_save), "?", &path_save);
	if (strcasecmp(method, HTTP_POST) || strcasecmp(path, PATH_TODOS))
		return (strdup(HTTP_404));
	printf("Path: %s\n", path);
	while ((header = strtok_r(NULL, CRLF, &request_save)))
	{
		key = trimwhitespace(strtok_r(header, ":", &header_save));
		value = trimwhitespace(strtok_r(NULL, CRLF, &header_save));
		if (!strcasecmp(key, CONTENT_TYPE))
			urlencoded = !strcasecmp(
				value, CONTENT_TYPE_X_WWW_FORM_URLENCODED);
		if (!strcasecmp(key, CONTENT_LENGTH))
			content_length = strtoul(value, NULL, 10);
	}
	if (!urlencoded)
		return (strdup(HTTP_400));
	if (content_length == 0)
		return (strdup(HTTP_411));
	return (post_request(body, content_length));
}

/**
 * post_request - parse a post request
 *
 * @body: pointer to the start of the request body
 * @content_length: length of the request body
 *
 * Return: response to send to client
 */
char *post_request(char *body, size_t content_length)
{
	char *query, *key, *value, *body_save, *query_save;
	char *title = NULL, *description = NULL;
	char buf1[2048] = {0};
	char buf2[2048] = {0};
	todo_t *todo = NULL;

	body[content_length] = 0;
	query = strtok_r(body, "&", &body_save);
	while (query)
	{
		key = strtok_r(query, "=", &query_save);
		value = strtok_r(NULL, "=", &query_save);
		printf("Body param: \"%s\" -> \"%s\"\n", key, value);
		if (!strcasecmp(key, TODO_TITLE))
			title = value;
		if (!strcasecmp(key, TODO_DESCRIPTION))
			description = value;
		query = strtok_r(NULL, "&", &body_save);
	}
	if (!title || !description)
		return (strdup(HTTP_422));
	todo = calloc(1, sizeof(*todo));
	if (!todo)
		return (NULL);
	todo->id = id++;
	todo->title = strdup(title);
	todo->description = strdup(description);
	todo->next = todo_head;
	todo_head = todo;
	sprintf(buf2,
		"{\"" TODO_ID "\":%d,\""
		TODO_TITLE "\":\"%s\",\""
		TODO_DESCRIPTION "\":\"%s\"}",
		todo->id, todo->title, todo->description);
	sprintf(buf1,
		HTTP_201_NOCRLF CRLF CONTENT_LENGTH ": %lu" CRLF
		CONTENT_TYPE ": " CONTENT_TYPE_JSON CRLF CRLF "%s",
		strlen(buf2), buf2);
	return (strdup(buf1));
}
