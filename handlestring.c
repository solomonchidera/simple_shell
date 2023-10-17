#include "solomon.h"

/**
 * _strcomp - performs comparison of two strangs.
 *
 * @st1: the first strang
 * @st2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, 0 if s1 == s2
 */
int _strcomp(char *st1, char *st2)
{
	while (*st1 && *st2)
	{
		if (*st1 != *st2)
			return (*st1 - *st2);
		st1++;
		st2++;
	}
	if (*st1 == *st2)
		return (0);
	else
		return (*st1 < *st2 ? -1 : 1);
}

/**
 * _strcpy - a function that copies the string pointed to by src
 * including the terminating null byte (\0), to the buffer pointed to by dest
 *
 *@src: input string of character
 *
 *@dest: input string of character
 *
 * Return: character (Success)
 */

char *_strcpy(char *dest, char *src)
{
	int y = -1;

	while (src[y] != '\0')
	{
		y++;
		dest[y] = src[y];
	}

	return (dest);
}
