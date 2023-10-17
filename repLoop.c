#include "solomon.h"
#include "source.h"
#include "parser.h"

int main(void)
{
	char *command;

	do
	{
		display_prompt1();
		command = display_command();

		if(!command)
		{
			exit(EXIT_SUCCESS);
		}
		if(command[0] == '\0' || _strcomp(command, "\n") == 0)
		{
			free(command);
			continue;
		}
		if(_strcomp(command, "exit\n") == 0)
		{
			free(command);
			break;
		}
		struct source src;
		src.bu   = command;
		src.busize  = strlen(command);
		src.cur_pos   = INIT_SRC_POS;
		parse_and_execute(&src);
		free(command);
	} while(1);
	exit(EXIT_SUCCESS);
}

char *display_command(void)
{
	char buffer[1024];
	char *p = NULL;
	char lenpointer = 0;
	int blength;
	char *p2;

	while(fgets(buffer, 1024, stdin))
	{
		blength = strlen(buffer);

		if(!p)
		{
			p = malloc(blength + 1);
		}
		else
		{
			p2 = realloc(p, lenpointer + blength + 1);

			if(p2)
			{
				p = p2;
			}
			else
			{
				free(p);
				p = NULL;
			}
		}
		if(!p)
		{
			_puts("error: failed to alloc buffer");
			return (NULL);
		}
		strcpy(p + lenpointer, buffer);

		if(buffer[blength - 1] == '\n')
		{
			if(blength == 1 || buffer[blength - 2] != '\\')
			{
				return (p);
			}
			p[lenpointer + blength - 2] = '\0';
			blength -= 2;
			display_prompt2();
		}

		lenpointer += blength;
	}
	return (p);
}

/**
 * parse_and_execute - a function to handle the parse and execute part
 * of the shell, it parses and executes simple commands, one command
 * at a time, until the input is consumed
 *
 * @src: from type source_s
 *
 * Return: returns control to the REPL loop in the main() function
 */

int parse_and_execute(struct source *src)
{
	skip_whitespace(src);

	struct tokens *tk = tokenizing(src);

	if(tk == &end_of_tok)
	{
		return 0;
	}

	while(tk && tk != &end_of_tok)
	{
		struct nodes *cmd = parse_simple_cmd(tk);

		if(!cmd)
		{
			break;
		}

		do_simple_command(cmd);
		free_nodetree(cmd);
		tk = tokenizing(src);
	}

	return 1;
}

