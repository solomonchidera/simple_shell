#include "moniaar.h"

/**
 * own_exit - causes normal process termination
 * @args: empty args
 *
 * Return: 0 to terminate the process
 */
int own_exit(char **args)
{
	/* exit with status */
	if (args[1])
	{
		int curr_status;
		curr_status = atoi(args[1]);

		if (curr_status >= 0)
		{
			return (curr_status);
		}
		else
		{
			return (1);
		}
	}
	/* exit success */
	else
	{
		return (1);
	}
}
