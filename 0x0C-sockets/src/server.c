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

#include "http.h"
#include "server.h"
#include "util.h"

/**
 * start_server - start a server and begin accepting connections
 *
 * @port: port on which to listen
 *
 * Return: If an error occurs, return EXIT_FAILURE.
 * Otherwise, return EXIT_SUCCESS.
 */
int start_server(unsigned short int port)
{
	struct sockaddr_in server = {0};
	socklen_t server_sz = sizeof(server);
	int server_sd = socket(AF_INET, SOCK_STREAM, 0);

	setbuf(stdout, NULL);
	setbuf(stderr, NULL);

	if (server_sd == -1)
	{
		error(0, errno, "Failed to create socket");
		return (EXIT_FAILURE);
	}
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(server_sd, (struct sockaddr *) &server, server_sz) == -1)
	{
		error(0, errno, "Failed to bind to address");
		return (EXIT_FAILURE);
	}
	if (listen(server_sd, BACKLOG) == -1)
	{
		error(0, errno, "Failed to listen for connections");
		return (EXIT_FAILURE);
	}
	printf("Server listening on port %d\n", ntohs(server.sin_port));
	while (1)
		accept_connections(server_sd);
	close(server_sd);
	return (EXIT_SUCCESS);
}

/**
 * accept_connections - accept connection from a client
 *
 * @server_sd: server socket descriptor
 *
 * Return: If an error occurs, return EXIT_FAILURE.
 * Otherwise, return EXIT_SUCCESS.
 */
int accept_connections(int server_sd)
{
	struct sockaddr_in client = {0};
	socklen_t client_sz = sizeof(client);
	int client_sd = -1;
	char ip[INET_ADDRSTRLEN + 1] = {0};
	char request[REQUEST_BUF_SZ] = {0};
	char *response = NULL;

	client_sd = accept(server_sd, (struct sockaddr *) &client, &client_sz);
	if (client_sd == -1)
	{
		error(0, errno, "Failed to accept connection");
		return (EXIT_FAILURE);
	}
	if (!inet_ntop(AF_INET, &client.sin_addr, ip, INET_ADDRSTRLEN))
	{
		error(0, errno, "Failed to get client address");
		close(client_sd);
		return (EXIT_FAILURE);
	}
	if (recv_request(client_sd, request, REQUEST_BUF_SZ) == -1)
	{
		error(0, errno, "Failed to receive request from client");
		close(client_sd);
		return (EXIT_FAILURE);
	}
	printf("Client connected: %s\n", ip);
	printf("Raw request: \"%s\"\n", request);
	response = handle_request(request);
	if (response && send_response(client_sd, response) == -1)
	{
		error(0, errno, "Failed to send response to client");
		free(response);
		close(client_sd);
		return (EXIT_FAILURE);
	}
	free(response);
	close(client_sd);
	return (EXIT_SUCCESS);
}

/**
 * recv_request - receive a request from a client
 *
 * @client_sd: client socket file descriptor from which to recieve a request
 * @request_buf: buffer into which to receive the request
 * @request_buf_sz: size of the buffer into which to receive the request
 *
 * Return: If an error occurs, return -1.
 * Otherwise, return the number of characters received.
 */
ssize_t recv_request(int client_sd, char *request_buf, size_t request_buf_sz)
{
	return (recv(client_sd, request_buf, request_buf_sz - 1, 0));
}

/**
 * send_response - send a response to a client
 *
 * @client_sd: client socket file descriptor from which to recieve a request
 * @response: response to send the the client
 *
 * Return: If an error occurs, return -1.
 * Otherwise, return the number of characters sent.
 */
ssize_t send_response(int client_sd, const char *response)
{
	return (send(client_sd, response, strlen(response), 0));
}
