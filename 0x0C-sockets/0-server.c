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

/**
 * main - entry point
 *
 * Return: If an error occurs, return EXIT_FAILURE.
 * Otherwise, return EXIT_SUCCESS.
 */
int main(void)
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in server = {0};

	if (sockfd == -1)
		error(EXIT_FAILURE, errno, "failed to create socket");
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sockfd, (struct sockaddr *) &server, sizeof(server)) == -1)
		error(EXIT_FAILURE, errno, "failed to bind address");
	if (listen(sockfd, BACKLOG) == -1)
		error(EXIT_FAILURE, errno, "failed to listen for connections");
	printf("Server listening on port %d\n", ntohs(server.sin_port));

	while (1)
		;

	close(sockfd);
	return (EXIT_SUCCESS);
}
