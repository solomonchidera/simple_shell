#include "moniaar.h"

/**
 * cd - changes the working dir of the current shell executon env
 * @args: target directory
 *
 * Return: 1 one success, 0 otherwise.
 */
int cd(char **args)
{
	if (args[1] == NULL)
	{
		_puts("expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("error in own_cd.c: changing dir\n");
		}
	}
	return (-1);
}
