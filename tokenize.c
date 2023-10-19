#include "moniaar.h"

/**
 * split_line - split a string into multiple strings
 * @line: string to be splited
 *
 * Return: pointer that points to the new array
 */
char **split_line(char *line)
{
	int bufsize, i;
	char **tokens;
	char *token;

	bufsize = 64;
	i = 0;
	tokens = malloc(bufsize * sizeof(char *));

	if (!tokens)
	{
		_puts("allocation error in split_line: tokensi\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		/* handle comments */
		if (token[0] == '#')
		{
			break;
		}
		tokens[i] = token;
		i++;
		if (i >= bufsize)
		{
			bufsize += bufsize;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				_puts("reallocation error in split_line: tokens\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}
