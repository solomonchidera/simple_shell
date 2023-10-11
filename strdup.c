#include "shell.h"

/**
 * strdup_ - a function to duplicate string
 *
 * @string: the string to duplicating
 *
 * Return: pointer to the duplicated string
 */

char strdup_(char *string)
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
