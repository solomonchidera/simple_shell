#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024

char *find_command_in_path(const char *command)
{
	char *path = getenv("PATH");
	char *token = strtok(path, ":");

	while (token != NULL)
	{
		char full_path[MAX_PATH_LENGTH];
		write(1, &full_path, strlen(full_path));
		_printf("%d", MAX_PATH_LENGTH);
		write(1, &token, strlen(token));
		write(1, &command, strlen(command));

		if (access(full_path, X_OK) == 0)
		{
			return strdup_(full_path);
		}

		token = strtok(NULL, ":");
	}

	return NULL;
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <command>\n", argv[0]);
		return 1;
	}

	char *command = argv[1];
	char *path_to_command = find_command_in_path(command);

	if (path_to_command != NULL) {
		printf("Found %s at: %s\n", command, path_to_command);
		free(path_to_command);
	} else {
		printf("%s not found in PATH\n", command);
	}

	return 0;
}
