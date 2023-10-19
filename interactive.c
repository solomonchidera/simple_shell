#include "moniaar.h"

/**
 * shell_is_interactive - UNIX command line interpreter
 *
 * Return: void
 */
void shell_is_interactive(void)
{
	char *line;
	char **args;
	int status;

	status = -1;

	do {
		_puts(")--> ");
		line = read_line(); /* read line from stdin */
		args = split_line(line); /* tokenize line */
		status = execute_args(args);
		/* avoid memory leaks */
		free(line);
		free(args);
		/* exit with status */
		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
