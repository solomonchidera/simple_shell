#include "shell.h"

/**
 * sloop - the shell main loop
 *
 * @n: a variable from struct details
 *
 * @av: argument vector
 *
 * Return: 0 Upon success, -1 upon error
 */

int sloop(details *n, char **av)
{

        ssize_t k;
        int builtin;

        k = 0;

        builtin = 0;

        while (k != -1 && builtin != -2)
        {
                clear_(n);
                if (_interactive(n))
                        display_prompt;
                k = userinput(n);
                if (r != -1)
                {
                        set_details(n, av);
                        builtin = find_(n);
                        if (builtin == -1)
				find_command_in_path(n);
                }
                else if (_interactive(n))
                        _putchar(10);

        }
        return (builtin);
}

/**
 * find_ - a function to search for a built in command
 *
 * @n: paramater from details struct type
 *
 * Return: -1 if not found, 0 if built-in executed successfully,
 * 1 if found but not successful. -2 for built-in signal only exit()
 */

int find_(details *n)
{

        int k, builtin;

	builtin = -1;

        k = 0;

        built_t table[] = {
                {"exit", _exit},
                {"cd", _newcd},
                {"env", _env},
                {NULL, NULL}
        };

        for (k = 0 ; table[k].flag ; k++)
                if (_strcomp(n->argv[0], table[k].flag) == 0)
                {
                        n->l_errorcount++;
                        builtin = table[k].fu(n);
                        break;
                }
        return (builtin);
}
