#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>


int main()
{
	char *line = NULL;
	size_t len = 0;
	char *argv[2] = {NULL, NULL};
	ssize_t read;
	while (1)
	{
		printf("$ ");
		
		read = getline(&line, &len, stdin);
		
		if (read == -1)
		{
			if (feof(stdin))
			{
				printf("\nExiting shell....\n");
				break;
			}
			else
			{
				fprintf(stderr, "Error readign input\n");
				break;
			}
		}
		if (read > 0 && line[read - 1] == '\n')
		{
			line[read - 1] = '\0';
		}
		if (line[0] == '\0')
		{
			continue;
		}
		argv[0] = line;

		if (execve(argv[0], argv, NULL) == -1)
			perror("Error: ");
		free(line);
		line = NULL;
		len = 0;
	}
	return (0);
}
