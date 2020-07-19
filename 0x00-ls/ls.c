#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include "ls.h"

/**
 * main - entry point
 * @argc: the size of the argument vector
 * @argv: the argument vector
 */
int main(int argc, char **argv)
{
	DIR *dir = NULL;
	struct dirent *entry = NULL; 

	if (argc == 1)
	{
		dir = opendir(".");
		if (!dir)
		{
			perror(argv[0]);
			return (EXIT_FAILURE);
		}
		entry = readdir(dir);
		while (entry)
		{
			printf("%s", entry->d_name);
			entry = readdir(dir);
			if (entry)
				printf(" ");
		}
		closedir(dir);
		printf("\n");
	}
	return (EXIT_SUCCESS);
}
