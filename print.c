#include "shell.h"

/**
 * display - a printf function 
 *
 * @string: the string to be printed
 *
 * @value: the printed to be value
 *
 * Return: standard output
 */

void display(char *string, int value)
{
	int k;

	k = 0;

	for (; string[k] != '\0' ; k++)
	{
		write(value, &string[k], 1);
	}
}
