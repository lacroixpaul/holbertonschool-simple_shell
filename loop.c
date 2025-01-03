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
	char **commands;
	size_t len = 0;
	int status = 1, i = 0;

	while (status)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		if (read_input(&line, &len) == -1)
		{
			if (!isatty(STDIN_FILENO))
				break;
			if (isatty(STDIN_FILENO))
				printf("\n");
			perror(argv[0]);
			free(line);
			exit(feof(stdin) ? EXIT_SUCCESS : EXIT_FAILURE);
		}
		commands = split_commands(line);
		for (i = 0; commands[i] != NULL; i++)
		{
			args = split_line(commands[i]);
			if (args[0] != NULL)
			{
				if (strcmp(args[0], "exit") == 0)
					exit_builtin(args, line);
				else if (strcmp(args[0], "env") == 0)
					_env(envp);
				else
				{
					char *full_path = find_executable(args[0], envp);

					if (full_path != NULL)
						status = execute_command(args, argv, envp);
					else
						fprintf(stderr, "%s: command not found\n", args[0]);
				}
			}
		free(args);
		}
		free(line);
		line = NULL;
		len = 0;
		if (!isatty(STDIN_FILENO))
			continue;
	}
	free(line);
}
