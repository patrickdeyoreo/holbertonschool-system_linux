#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "api.h"
#include "http.h"
#include "todo.h"

static unsigned int id;
static todo_t *todo_head;
static todo_t *todo_tail;

/**
 * api_route - dispatch an API call to the appropriate function
 *
 * @request: HTTP request to dispatch
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a response to send to the client.
 */
char *api_route(http_request_t *request)
{
	static api_endpoint_t api_endpoints[] = {
		{PATH_TODOS, HTTP_GET, get_todos},
		{PATH_TODOS, HTTP_POST, post_todos},
		{PATH_TODOS, HTTP_DELETE, delete_todos},
		{NULL, NULL, NULL}
	};
	api_endpoint_t *api_endpoint = api_endpoints;

	while (api_endpoint->path)
	{
		if (!strcasecmp(request->path, api_endpoint->path) &&
		    !strcasecmp(request->method, api_endpoint->method))
			return (api_endpoint->fn(request));
		api_endpoint += 1;
	}
	return (strdup(HTTP_404));
}

/**
 * post_todos - POST request to todos endpoint
 *
 * @request: HTTP request
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a response to send to the client.
 */
char *post_todos(http_request_t *request)
{
	char *query, *key, *value, *body_save, *query_save;
	char *title = NULL, *description = NULL;
	char buf1[BUF_SZ] = {0}, buf2[BUF_SZ] = {0};
	todo_t *todo = NULL;
	dict_item_t *content_length_item = dict_get(request->headers, CONTENT_LENGTH);
	unsigned long int content_length = 0;

	if (content_length_item)
		content_length = strtoul(content_length_item->value, NULL, 10);
	if (content_length == 0)
		return (strdup(HTTP_411));
	request->body[content_length] = '\0';
	query = strtok_r(request->body, "&", &body_save);
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
	if (todo_tail)
		todo_tail->next = todo, todo_tail = todo;
	else
		todo_tail = todo_head = todo;
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
/**
 * get_todos - GET request to todos endpoint
 *
 * @request: HTTP request
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a response to send to the client.
 */
char *get_todos(http_request_t *request __attribute__((unused)))
{
	char buf1[BUF_SZ] = {0}, buf2[BUF_SZ] = {0};
	todo_t *todo = todo_head;

	buf2[0] = '[';
	while (todo)
	{
		sprintf(buf2 + strlen(buf2),
			"{\"" TODO_ID "\":%d,\""
			TODO_TITLE "\":\"%s\",\""
			TODO_DESCRIPTION "\":\"%s\"}%s",
			todo->id, todo->title, todo->description,
			todo->next ? "," : "");
		todo = todo->next;
	}
	buf2[strlen(buf2)] = ']';
	sprintf(buf1,
		HTTP_200_NOCRLF CRLF CONTENT_LENGTH ": %lu" CRLF
		CONTENT_TYPE ": " CONTENT_TYPE_JSON CRLF CRLF "%s",
		strlen(buf2), buf2);
	return (strdup(buf1));
}

/**
 * delete_todos - DELETE request to todos endpoint
 *
 * @request: HTTP request
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a response to send to the client.
 */
char *delete_todos(http_request_t *request __attribute__((unused)))
{
	return (NULL);
}
