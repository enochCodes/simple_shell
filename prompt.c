#include "shell.h"
/**
 * printprompt - prints prompt
 *
 * Returns: 0
 */
void printprompt(void)
{
	if (isatty(0))
	{
		write(STDOUT_FILENO, "#fun$ ", 9);
		fflush(stdout);
	}
}
