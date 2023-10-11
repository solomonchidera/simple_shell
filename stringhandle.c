#include "shell.h"

/**
 * _strlen - returns the length of a string
 *
 * @string: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *string)
{
	int i = 0;

	if (!string)
		return (0);

	while (*string++)
		i++;
	return (i);
}

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
 * _strcat - concatenates two strings
 *
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);

}

/**
 * locateChar - locates a character in a string
 *
 *@string: the string to be parsed
 *
 *@c: the character to look for
 *
 *Return: string of located characters
 */

char *locateChar(char *string, char c)
{
	do {
		if (*string == c)
			return (string);
	}
       	while (*string++ != '\0');

	return (NULL);
}
