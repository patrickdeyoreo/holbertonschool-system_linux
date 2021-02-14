#include <arpa/inet.h>
#include <errno.h>
#include <error.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 12345
#define BACKLOG (1 << 6)
#define READ_BUF_SZ (1 << 12)
#define REQUEST_BUF_SZ (1 << 12)

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
	ssize_t nread = -1;
	int errno_tmp = 0;

	client_sd = accept(server_sd, (struct sockaddr *) &client, &client_sz);
	if (client_sd == -1)
	{
		error(0, errno, "failed to accept connection");
		return (EXIT_FAILURE);
	}
	if (!inet_ntop(AF_INET, &client.sin_addr, ip_buf, INET_ADDRSTRLEN))
	{
		error(0, errno, "failed to get client address");
		close(client_sd);
		return (EXIT_FAILURE);
	}
	printf("Client connected: %s\n", ip_buf);
	printf("Message received: ");
	printf("\"");
	while ((nread = read(client_sd, request_buf, REQUEST_BUF_SZ - 1)) > 0)
	{
		request_buf[nread] = '\0';
		printf("%s", request_buf);
	}
	errno_tmp = errno;
	printf("\"");
	printf("\n");
	if (nread == -1)
	{
		error(0, errno_tmp, "failed to read");
		close(client_sd);
		return (EXIT_FAILURE);
	}
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

	if (server_sd == -1)
		error(EXIT_FAILURE, errno, "failed to create socket");
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(server_sd, (struct sockaddr *) &server, server_sz) == -1)
		error(EXIT_FAILURE, errno, "failed to bind address");
	if (listen(server_sd, BACKLOG) == -1)
		error(EXIT_FAILURE, errno, "failed to listen for connections");
	printf("Server listening on port %d\n", ntohs(server.sin_port));
	accept_connections(server_sd);
	close(server_sd);
	return (EXIT_SUCCESS);
}
