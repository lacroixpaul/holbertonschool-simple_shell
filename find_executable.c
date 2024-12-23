#include "header.h"

/**
* find_executable - handle the path.
* @command : command to search.
* @envp : environnement variable.
* Return: 1 in case of sucess otherwise return 0.
**/

char *find_executable(char *command, char *envp[])
{
	static char full_path[256];
	char *path = NULL;
	char *dir;
	int i = 0;
	char path_copy[1024];

	if (command[0] == '/')
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
	strcpy(path_copy, path);
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
			return (full_path);
		dir = strtok(NULL, ":");
	}
	return (NULL);
}
