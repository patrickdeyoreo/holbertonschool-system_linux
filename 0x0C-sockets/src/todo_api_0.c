#include <arpa/inet.h>
#include <errno.h>
#include <error.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "server.h"

/**
 * parse_request - parse a request
 *
 * @request: pointer to the start of the null-terminated request
 */
static void parse_request(const char *request)
{
	const char *stop = strchr(request, ' ');

	printf("Method: ");
	write(STDOUT_FILENO, request, stop - request);
	printf("\n");
	request = stop + 1;
	stop = strchr(request, ' ');
	printf("Path: ");
	write(STDOUT_FILENO, request, stop - request);
	printf("\n");
	request = stop + 1;
	stop = strchr(request, '\n');
	printf("Version: ");
	write(STDOUT_FILENO, request, stop - request);
	printf("\n");
}

/**
 * accept_connections - accept connection from a client
 *
 * @server_sd: server socket descriptor
 *
 * Return: If an error occurs, return EXIT_FAILURE.
 * Otherwise, return EXIT_SUCCESS.
 */
static int accept_connections(int server_sd)
{
	struct sockaddr_in client = {0};
	socklen_t client_sz = sizeof(client);
	int client_sd = -1;
	char ip_buf[INET_ADDRSTRLEN + 1] = {0};
	char request_buf[REQUEST_BUF_SZ] = {0};

	client_sd = accept(server_sd, (struct sockaddr *) &client, &client_sz);
	if (client_sd == -1)
	{
		error(0, errno, "Failed to accept connection");
		return (EXIT_FAILURE);
	}
	if (!inet_ntop(AF_INET, &client.sin_addr, ip_buf, INET_ADDRSTRLEN))
	{
		error(0, errno, "Failed to get client address");
		close(client_sd);
		return (EXIT_FAILURE);
	}
	printf("Client connected: %s\n", ip_buf);
	if (recv(client_sd, request_buf, REQUEST_BUF_SZ - 1, 0) == -1)
	{
		error(0, errno, "Failed to read client request");
		close(client_sd);
		return (EXIT_FAILURE);
	}
	printf("Raw request: \"%s\"\n", request_buf);
	parse_request(request_buf);
	send(client_sd, HTTP_RESPONSE_200, strlen(HTTP_RESPONSE_200), 0);
	close(client_sd);
	return (EXIT_SUCCESS);
}

/**
 * main - entry point
 *
 * Return: If an error occurs, return EXIT_FAILURE.
 * Otherwise, return EXIT_SUCCESS.
 */
int main(void)
{
	struct sockaddr_in server = {0};
	socklen_t server_sz = sizeof(server);
	int server_sd = socket(AF_INET, SOCK_STREAM, 0);

	setbuf(stdout, NULL);
	setbuf(stderr, NULL);

	if (server_sd == -1)
		error(EXIT_FAILURE, errno, "Failed to create socket");
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(server_sd, (struct sockaddr *) &server, server_sz) == -1)
		error(EXIT_FAILURE, errno, "Failed to bind to address");
	if (listen(server_sd, BACKLOG) == -1)
		error(EXIT_FAILURE, errno, "Failed to listen for connections");
	printf("Server listening on port %d\n", ntohs(server.sin_port));
	while (1)
		accept_connections(server_sd);
	close(server_sd);
	return (EXIT_SUCCESS);
}
