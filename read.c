#include "moniaar.h"

/**
 * read_stream - read a line from the stream
 *
 * Return: pointer that points the the read line
 */
char *read_stream(void)
{
	int i, character, bufsize;
	char *line;

	bufsize = 1024, i = 0;
	line = malloc(sizeof(char) * bufsize);

	if (line == NULL)
	{
		_puts("allocation error in read_stream\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = getchar(); /* read first char from stream */
		if (character == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (character == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		else
		{
			line[i] = character;
		}
		i++;
		if (i >= bufsize)
		{
			bufsize += bufsize;
			line = realloc(line, bufsize);
			if (line == NULL)
			{
				_puts("reallocation error in read_stream\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
