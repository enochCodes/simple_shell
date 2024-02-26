#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *line = NULL;
	size_t len;

	len = 0;
	
	while (1)
	{
		printf("$");
		ssize_t read = getline(&line, &len, stdin);
		
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
		if (exc

	}
	
	free(line);
	return (0);
}
