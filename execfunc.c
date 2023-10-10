#include "shell.h"

/**
 * exec_command - a function to handle the execution of
 * your input command
 *
 * @command: the command input by the user
 *
 * Return: Nothing
 */

void exec_command(const char *commands)
{
	pid_t childpid = fork();

	if (childpid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (childpid == 0)
	{
		execlp(commands, commands, (char *)NULL);
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
}
