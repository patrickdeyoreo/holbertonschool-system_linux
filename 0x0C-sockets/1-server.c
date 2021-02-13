#include <arpa/inet.h>
#include <errno.h>
#include <error.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BACKLOG 64
#define PORT 12345
#define READ_BUF_SZ (1024 * 8)
#define REQUEST_BUF_SZ (1024 * 8)

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
	int client_sd = -1;
	struct sockaddr_in client = {0};
	socklen_t client_sz = sizeof(client);
	char ip_buf[INET_ADDRSTRLEN + 1] = {0};
	char request_buf[REQUEST_BUF_SZ + 1] = {0};
	ssize_t n_read = 0;

	client_sd = accept(server_sd, (struct sockaddr *) &client, &client_sz);
	if (client_sd == -1)
		return (error(0, errno, "failed to accept"), EXIT_FAILURE);
	if (!inet_ntop(AF_INET, &client.sin_addr, ip_buf, INET_ADDRSTRLEN))
		return (error(0, errno, "failed to get IP"), EXIT_FAILURE);
	printf("Client connected: %s\n", ip_buf);
	while ((n_read = read(client_sd, request_buf, REQUEST_BUF_SZ)) > 0)
	{
		request_buf[n_read] = '\0';
		printf("%s", request_buf);
	}
	if (n_read == -1)
		return (error(0, errno, "failed to read"), EXIT_FAILURE);

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
	int server_sd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in server = {0};

	if (server_sd == -1)
		error(EXIT_FAILURE, errno, "failed to create socket");
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(server_sd, (struct sockaddr *) &server, sizeof(server)) == -1)
		error(EXIT_FAILURE, errno, "failed to bind address");
	if (listen(server_sd, BACKLOG) == -1)
		error(EXIT_FAILURE, errno, "failed to listen for connections");
	printf("Server listening on port %d\n", ntohs(server.sin_port));

	accept_connections(server_sd);
	close(server_sd);

	return (EXIT_SUCCESS);
}
