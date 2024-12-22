#include "header.h"

/**
* loop - infinite boucle of the shell.
* @envp : environnement variable.
* Return: void.
**/

void loop(char *envp[])
{
	char *line = NULL;
	char **args;
	size_t len = 0;
	int status = 1;

	while (status)
	{
		if (isatty(STDIN_FILENO))
		{
		printf("#cisfun$ ");
		}
		if (read_input(&line, &len) == -1)
		{
			if (feof(stdin))
			{
			free(line);
			exit(EXIT_SUCCESS);
			}
			else
			{
				perror("read_input");
				free(line);
				exit(EXIT_FAILURE);
			}
		}
		args = split_line(line);
		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
				status = 0;
			else
				status = execute_command(args, envp);
		}
		free(args);
		if (!isatty(STDIN_FILENO))
			break;
	}
	free(line);
}
