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
	char **commands;
	size_t len = 0;
	int status = 1;

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
			line = NULL;
			exit(feof(stdin) ? EXIT_SUCCESS : EXIT_FAILURE);
		}
		commands = split_commands(line);
		status = process_commands(commands, argv, envp);
		free(line);
		len = 0;
		if (!isatty(STDIN_FILENO))
			continue;
	}
}

/**
* process_commands - process each command from the input line.
* @commands : array of commands.
* @argv : array of arguments.
* @envp : environment variables.
* Return: 1 to continue the loop, 0 to exit.
**/

int process_commands(char **commands, char *argv[], char *envp[])
{
	char **args;
	int status = 1;
	int i = 0, j = 0;

		for (i = 0; commands[i] != NULL; i++)
		{
			args = split_line(commands[i]);
			if (args[0] != NULL)
			{
				if (strcmp(args[0], "exit") == 0)
					exit_builtin(args, commands[i]);
				else if (strcmp(args[0], "env") == 0)
					_env(envp);
				else
				{
					char *full_path = find_executable(args[0], envp);

					if (full_path != NULL)
					{
						status = execute_command(args, argv, envp);
						free(full_path);
					}
					else
						fprintf(stderr, "%s: command not found\n", args[0]);
				}
			}
			for (j = 0; args[j] != NULL; j++)
			{
				free(args[j]);
			}
			free(args);
		}
	return (status);
}
