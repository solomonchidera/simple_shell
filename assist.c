#include "moniaar.h"

/**
 * assist - print help
 * @args: arguments
 *
 * Return: 1 on success, 0 otherwise
 */
int assist(char **args)
{
	char *builtin_func_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	unsigned long int i = 0;
	(void)(**args);

	_puts("\n---help simple_shell---\n");
	_puts("Type a command and its arguments, then hit enter\n");
	_puts("Built-in commands:\n");
	for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
		printf("  -> %s\n", builtin_func_list[i]);
	}
	_puts("Use the man command for information on other programs.\n\n");
	return (-1);
}
