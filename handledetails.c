#include "shell.h"

/**
 * clear_ - initialize details struct
 *
 * @n: structure address
 */

void clear_(details n)
{
        n->arg = NULL;
        n->argv = NULL;
        n->path = NULL;
        n->argc = 0;
}

/**
 * set_details - initilaize details structure
 *
 * @a: structure address
 *
 * @av: argument vector
 */

void set_details(details *a, char **av)
{
        int k;

        k = 0;

        a->fname = av[0];
        if (a->arg)
        {
                a->argv = split(a->arg, "\t");
                if (!a->arg)
                {
                        a->argv = malloc(sizeof(char *) * 2);
                        if (a->argv)
                        {
                                a->argv[0] = strdup_(a->arg);
                                a->argv[1] = NULL;
                        }
                }
                for (k = 0 ; a->argv && a->argv[k] ; k++)
                        ;
                a->argc = k;
        }
	free(a->arg[0]);
}


/**
 * split - a function to split a string into 2 words
 *
 * @string: input string
 *
 * @del: delimeter string
 *
 * Return: a pointer to a string of arrays
 */

char **split(char *string, char *del)
{
        int q, r, st, t, words;

        words = 0;

        char **s;

        if (string == NULL || string[0] == 0)
		return (NULL);
        if (!del)
                del = " ";
        for (q = 0 ; string[q] != '\0' ; q++)
        {
                if (!delim_(string[q], del) && (check_del(string[q + 1], del) || !string[q + 1]))
                                words++;
        }
        if (words == 0)
                return (NULL);
        s = malloc((1 + words) * sizeof(char *));

        if (!s)
                return (NULL);
        for (q = 0, r = 0 ; r < words ; r++)
        {
                while (check_del(string[q], del))
                        q++;
                st = 0;

                while (!check_del(string[q + st], del) && string[q + st])
                        st++;

                s[r] = malloc((st + 1) * sizeof(char *));

                if (!s[r])
                {
                        for (st = 0; st < r ; st++)
                                free(s[st]);
                        free(s);
                        return (NULL);
                }
                for (t = 0 ; t < st ; t++)
                        s[r][t] = string[q++];
                s[r][t] = 0;
        }
        s[r] = NULL;
        return (s);
}
