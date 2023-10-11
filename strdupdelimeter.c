#include "shell.h"

/**
 * check_del - check if the character is a delimeter
 *
 * @ch: character to check
 *
 * @del: the delimater string
 *
 * Return: 1 if true, 0 if not
 */

int check_del(char ch, char *del)
{
        while (*del)
                if (*del++ == ch)
                        return (1);
        return (0);
}

/**
 * strdup_ - a function to duplicate string
 *
 * @string: the string to duplicating
 *
 * Return: pointer to the duplicated string
 */

char strdup_(const char *string)
{
        int len;
        char *r;

        len = 0;

        if (string == NULL)
                return (NULL);
        while (*string++)
                len++;
        r = malloc(sizeof(char) * (len + 1));
        if (!r)
                return (NULL);
        for (len++; len-- ; )
                r[len] = *--string;
        return (string);
}
