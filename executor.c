#include "header.h"

/**
* execute_command - read the user input.
* @args : array of string to use as argument.
* Return: 1 in case of sucess otherwise return 0.
**/

int execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		fprintf(stderr, "fork error\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			fprintf(stderr, "execvp error\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
