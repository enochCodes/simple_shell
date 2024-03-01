#include "shell.h"
/**
 * token - tokenizes input
 *@input: argument
 *@delim: delimiter
 *
 * Return: number of words
 */
size_t token(char *input, char *delim)
{
	size_t words_count = 0;

	if (strtok(input, delim))
	{
		++words_count;
	}
	while (strtok(NULL, delim))
	{
		++words_count;
	}
	return (words_count);
}
/**
 * wordlist - lists
 *@input: string
 *@delim: delimiter
 *
 * Return: array of ptr
 */
char **wordlist(char *input, char *delim)
{
	char **args = NULL;
	size_t args_i = 0;
	size_t args_s = 0, input_i;
	size_t input_s = strlen(input);
	char prev_char = '\0';

	args_s = token(input, delim);
	if (args_s > 0)
	{
		args = malloc(sizeof(char *) * (args_s + 1));

		if (args == NULL)
		{
			exit(EXIT_FAILURE);
		}

		for (input_i = 0; input_i < input_s; ++input_i)
		{
			if (input[input_i] != '\0' && prev_char == '\0')
			{
				args[args_i] = input + input_i;
				++args_i;
			}
			prev_char = input[input_i];
		}
		args[args_i] = NULL;
	}
	return (args);
}
