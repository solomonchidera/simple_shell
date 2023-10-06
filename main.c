#include "shell.h"

int main(void)
{
	char commands[130];
	while (1)
	{
		display_prompt();
		user_command(commands, sizeof(commands));
		exec_command(commands);
	}
	return (0);
}
