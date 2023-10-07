#include "shell.h"

/**
 * user_command - a function to get the command from a user
 *
 * @commands: the input command entered
 *
 * @size: exact size of command entered
 *
 * Return: Nothing
 */

void user_command(char *commands, size_t size)
{
	if (fgets(commands, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			_puts("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("No such file or directory");
			exit(EXIT_FAILURE);
		}
	}
	commands[strcspn(commands, "\n")] = '\0';
}
