#include "header.h"

/**
* find_executable - handle the path.
* @command : command to search.
* @envp : environnement variable.
* Return: full_path of the command or NULL.
**/

char *find_executable(char *command, char *envp[])
{
	static char full_path[1024];
	char *path = NULL;
	char *path_copy = NULL;
	char *dir;
	int i = 0;

	if (command[0] == '/' || command[0] == '.' || command[0] == '~')
		return (access(command, X_OK) == 0 ? strdup(command) : NULL);
	for (i = 0; envp[i] != NULL; i++)
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			break;
		}
	}
	if (path == NULL)
		return (NULL);
	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		strncpy(full_path, dir, sizeof(full_path) - 1);
		full_path[sizeof(full_path) - 1] = '\0';
		strncat(full_path, "/", sizeof(full_path) - strlen(full_path) - 1);
		strncat(full_path, command, sizeof(full_path) - strlen(full_path) - 1);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (strdup(full_path));
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
