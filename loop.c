#include "header.h"

/**
* loop - infinite boucle of the shell.
* @envp : environnement variable.
* @argv : string of arguments.
* Return: void.
**/

void loop(char *argv[], char *envp[])
{
	char *line = NULL;
	char **args;
	size_t len = 0;
	int status = 1;

	while (status)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		if (read_input(&line, &len) == -1)
		{
			perror(argv[0]);
			free(line);
			exit(feof(stdin) ? EXIT_SUCCESS : EXIT_FAILURE);
		}
		args = split_line(line);
		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
				exit(EXIT_SUCCESS);
			else if (strcmp(args[0], "env") == 0)
				_env(envp);
			else
				status = execute_command(args, argv, envp);
		}
		free(args);
		if (!isatty(STDIN_FILENO))
			break;
	}
	free(line);
}
