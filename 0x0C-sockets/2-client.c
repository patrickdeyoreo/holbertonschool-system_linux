#include <arpa/inet.h>
#include <errno.h>
#include <error.h>
#include <limits.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "client.h"

#define PUSAGE(stream, program_name) \
	fprintf((stream), "Usage: %s <host> <port>\n", (program_name))

/**
 * strtoport - convert a string to a port number
 *
 * @str: string to convert
 *
 * Return: port number
 */
static unsigned short int strtoport(const char *str)
{
	char *str_end = NULL;
	long int port = strtol(str, &str_end, 10);

	if (*str == '\0' || *str_end != '\0')
		error(EXIT_FAILURE, 0, "%s: port must be an integer", str);
	if (port < 0 || port > USHRT_MAX)
		error(EXIT_FAILURE, 0, "%s: port out of range", str);
	return (port);
}

/**
 * connect_to_server - connect to a server
 *
 * @addr: addrinfo returned by getaddrinfo
 * @port: port number
 *
 * Return: If unable to connect to a server, return -1.
 * Otherwise, return the client socket file descriptor.
 */
int connect_to_server(struct addrinfo *addr, unsigned short int port)
{
	struct addrinfo *host = NULL;
	struct sockaddr_in *server = NULL;
	char ip_buf[INET_ADDRSTRLEN + 1] = {0};
	int client_sd = -1;

	for (host = addr; host; host = host->ai_next)
	{
		client_sd = socket(
			host->ai_family,
			host->ai_socktype,
			host->ai_protocol);
		if (client_sd == -1)
		{
			error(0, errno, "failed to create socket");
			continue;
		}
		server = (struct sockaddr_in *) host->ai_addr;
		inet_ntop(AF_INET, &server->sin_addr, ip_buf, INET_ADDRSTRLEN);
		server->sin_port = htons(port);
		printf("Attempting to connect to %s:%d ...\n", ip_buf, port);
		if (connect(client_sd, host->ai_addr, host->ai_addrlen) == -1)
		{
			error(0, errno, "failed to connect to host");
			close(client_sd);
			client_sd = -1;
			continue;
		}
		break;
	}
	return (client_sd);
}

/**
 * main - entry point
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: If an error occurs, return EXIT_FAILURE.
 * Otherwise, return EXIT_SUCCESS.
 */
int main(int argc, char **argv)
{
	struct addrinfo *addr = NULL;
	struct addrinfo hints = {0};
	int gai_errno = 0;
	int client_sd = -1;
	unsigned short int port = 0;

	if (argc != 3)
		return (PUSAGE(stderr, argv[0]), EXIT_FAILURE);
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	gai_errno = getaddrinfo(argv[1], NULL, &hints, &addr);
	if (gai_errno != 0)
		error(EXIT_FAILURE, 0, "%s", gai_strerror(gai_errno));
	port = strtoport(argv[2]);
	client_sd = connect_to_server(addr, port);
	freeaddrinfo(addr);
	if (client_sd == -1)
		error(EXIT_FAILURE, 0, "failed to connect to host");
	printf("Connected to %s:%d\n", argv[1], port);
	close(client_sd);
	return (EXIT_SUCCESS);
}
