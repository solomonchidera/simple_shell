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
