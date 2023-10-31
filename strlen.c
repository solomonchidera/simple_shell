#include "moniaar.h"

/**
 * _strlen - A function to return the length of a string
 * @s: input character
 *
 * Return: int length of a string
 */

int _strlen(char *s)
{
	int cnu;

	for (cnu = 0 ; *s != '\0' ; s++)
	{
		++cnu;
	}
	return (cnu);
}
