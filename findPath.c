#include "main.h"

/**
 * find_command_path - Find the path of a command
 * @command: The command to find the path for
 *
 * Return: The path of the command, or NULL if not found
 */
char *find_command_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");
	char *cmd_path;

	if (access(command, X_OK) == 0)
	{
		return command;
	}
	else
	{
		while (dir != NULL)
		{
			cmd_path = malloc(strlen(dir) + strlen(command) + 2);
			sprintf(cmd_path, "%s/%s", dir, command);
			if (access(cmd_path, X_OK) == 0)
			{
				free(path_copy);
				return cmd_path;
			}
			free(cmd_path);
			dir = strtok(NULL, ":");
		}
	}
	free(path_copy);
	return NULL;
}

