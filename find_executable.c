#include "header.h"

/**
* find_executable - handle the path.
* @command : command to search.
* @envp : environnement variable.
* Return: 1 in case of sucess otherwise return 0.
**/

char *find_executable(char *command, char *envp[])
{
	static char full_path[1024];
	char *path = NULL;
	char *dir;
	int i = 0;
	char path_copy[1024];

	if (command[0] == '/' || command[0] == '.' || command[0] == '~')
	{
		if (access(command, X_OK) == 0)
			return (command);
		return (NULL);
	}

	for (; envp[i] != NULL; i++)
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			break;
		}
	}
	if (path == NULL)
		return (NULL);
	strncpy(path_copy, path, sizeof(path_copy) - 1);
	path_copy[sizeof(path_copy) - 1] = '\0';
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		strncpy(full_path, dir, sizeof(full_path) - 1);
		full_path[sizeof(full_path) - 1] = '\0';
		strncat(full_path, "/", sizeof(full_path) - strlen(full_path) - 1);
		strncat(full_path, command, sizeof(full_path) - strlen(full_path) - 1);

		if (access(full_path, X_OK) == 0)
			return (full_path);
		dir = strtok(NULL, ":");
	}
	return (NULL);
}
