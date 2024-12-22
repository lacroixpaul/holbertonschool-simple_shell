#include "header.h"

/**
* execute_command - read the user input.
* @args : array of string to use as argument.
* @envp : environnement variable.
* Return: 1 in case of sucess otherwise return 0.
**/

int execute_command(char **args, char *envp[])
{
	pid_t pid;
	int status;

	if (access(args[0], F_OK) == -1)
	{
		perror("./hsh");
		return (1);
	}
	if (access(args[0], X_OK) == -1)
	{
		perror("Permission denied");
		return (1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		return (1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	return (1);
}
