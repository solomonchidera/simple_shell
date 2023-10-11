#include "shell.h"

/**
 * _exit - a function to act like the exit command from
 * the shell
 *
 * @status: the value of the exit funtion to the parent
 * process
 *
 * Return: Nothing (Void)
 */

void _exit(int status)
{
	if (status = 0 || = EXIT_SUCCESS)
		exit(0);
	else if (status = -1 || EXIT_FAILURE)
		exit(1);
}
