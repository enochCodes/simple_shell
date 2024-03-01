#include "shell.h"
/**
 * print_prompt - prints prompt
 *
 * Returns: 0
 */
void print_prompt(void)
{
	if (isatty(0))
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		fflush(stdout);
	}
}
