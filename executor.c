#include "header.h"

/**
* execute_command - execute the user input.
* @args : array of string to use as argument.
* @argv : array of strings which are arguments.
* @envp : environnement variable.
* Return: 1 in case of sucess otherwise return 0.
**/

int execute_command(char **args, char *argv[], char *envp[])
{
	pid_t pid;
	int status;
	char *full_path;

	full_path = find_executable(args[0], envp);
	if (!full_path)
	{
		fprintf(stderr, "%s: %s: command not found\n", argv[0], args[0]);
		return (1);
	}
	if (access(full_path, X_OK) != 0)
	{
		fprintf(stderr, "%s: %s: Permission denied\n", argv[0], full_path);
		free(full_path);
		return (1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror(argv[0]);
		free(full_path);
		return (1);
	}
	else if (pid == 0)
	{
		execve(full_path, args, envp);
		perror(argv[0]);
		free(full_path);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	free(full_path);
	return (1);
}
