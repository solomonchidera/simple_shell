#include "moniaar.h"

/**
 * own_exit - causes normal process termination
 * @args: empty args
 *
 * Return: 0 to terminate the process
 */

int own_exit(char **args)
{
	/* Check if there's an argument provided */
	if (args[1])
	{
		/* Use atoi to convert the argument to an integer */
		int exit_status = atoi(args[1]);

		/* Call the exit function with the specified exit status */
		exit(exit_status);
	}
	else
	{
		/* If no argument is provided, call exit with a status of 0 for a successful exit */
		exit(0);
	}

	return (0);
}
