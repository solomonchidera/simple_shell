#include "moniaar.h"

/**
 * own_exit - causes normal process termination
 * @args: empty args
 *
 * Return: 0 to terminate the process
 */
int own_exit(char **args)
{
	int curr_stat= EXIT_SUCCESS; 

	if (args[1]) 
	{
		curr_stat = atoi(args[1]); 
		free(args); 
		exit(curr_stat);
	} 

	else 
		free(args); 
	exit(0);
}
