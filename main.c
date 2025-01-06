#include "header.h"

/**
* read_input - read the user input.
* @input : double pointer to store the user input.
* @len : pointer to thesize of the buffer.
* Return: the number of reader characters or -1 if error.
**/

ssize_t read_input(char **input, size_t *len)
{
	ssize_t read;

	if (*input == NULL)
		*len = 0;

	read = getline(input, len, stdin);
	if (read == -1)
	{
		return (-1);
	}
	return (read);
}

/**
* execute_command - execute command.
* @args : double pointer to store the args.
* @envp : array of environnement variable.
* Return: nothing.
**/

void execute_command(char **args, char *envp[], char *input)
{
	pid_t pid;
	char *executable_path;

	if (strcmp(args[0], "env") == 0)
	{
		_env(envp);
		return;
	}
	else if (strcmp(args[0], "exit") == 0)
		exit_builtin(args, input);
	if (args[0][0] == '/')
		executable_path = strdup(args[0]);
	else
		executable_path = handle_path(envp, args[0]);
	if (executable_path == NULL)
	{
		fprintf(stderr, "Command not found: %s\n", args[0]);
		return;
	}
	if (args[0] == NULL)
		return;
	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		free(executable_path);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(executable_path, args, envp) == -1)
		{
			perror("execve error");
			free(executable_path);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);
	free(executable_path);
}

/**
* parse_input - divide the line into arguments.
* @input: pointer to the user input.
* Return: array of arguments or NULL if error.
**/

char **parse_input(char *input)
{
	int bufsize = 64, i = 0, j;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(input, " ");
	while (token != NULL)
	{
		tokens[i] = malloc(strlen(token) + 1);
		if (!tokens[i])
		{
			fprintf(stderr, "allocation error\n");
			for (j = 0; j < i; j++)
				free(tokens[j]);
			free(tokens);
			free(token);
			exit(EXIT_FAILURE);
		}
		strcpy(tokens[i], token);
		i++;
		if (i >= bufsize)
		{
			bufsize += 64;
			tokens = _realloc(tokens, (bufsize - 64) * sizeof(char *),
											bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "allocation error\n");
				for (j = 0; j < i; j++)
					free(tokens[j]);
				free(tokens);
				free(token);
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	return (tokens);
}
/**
* handle_path - find the full path of a command.
* @envp: array of environment variables.
* @function_name: the name of the command to find.
* Return: the full path of the command or NULL if not found.
**/

char *handle_path(char *envp[], char *function_name)
{
	char *path_copy, *token;
	char *path_buffer = NULL;
	char *path = _getenv(envp);

	if (path == NULL)
	{
		fprintf(stderr, "PATH environnement variable not found \n");
		return (NULL);
	}
	path_copy = strdup(path);
	if (!path_copy)
	{
		perror("Error: strdup failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(path_copy, ":");
	while (token)
	{
		if (path_buffer)
		{
			free(path_buffer);
			path_buffer = NULL;
		}
		path_buffer = malloc(strlen(token) + strlen(function_name) + 2);
		if (!path_buffer)
		{
			perror("Error: malloc failed");
			free(path_copy);
			exit(EXIT_FAILURE);
		}
		strcpy(path_buffer, token);
		strcat(path_buffer, "/");
		strcat(path_buffer, function_name);
		if (access(path_buffer, X_OK) == 0)
		{
			free(path_copy);
			return (path_buffer);
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	if (path_copy)
		free(path_buffer);
	return (NULL);
}

/**
* main - infinite boucle of the shell.
* @argc : number of arguments.
* @argv : array of string of arguments.
* @envp : array of environnement variable.
* Return: 0.
**/

int main(int argc, char **argv, char *envp[])
{
	char *input = NULL;
	ssize_t read;
	size_t len = 0;
	char **args;
	int i;

	(void)argc, (void)argv;

	if (isatty(STDIN_FILENO))
	{
		while (1)
	{
		printf("Enter your will: ");
		read = read_input(&input, &len);
		if (read == -1)
		{
			perror("Exiting shell");
			break;
		}
		input[read - 1] = '\0';
		args = parse_input(input);
		if (args[0])
			execute_command(args, envp, input);
		for (i = 0; args[i]; i++)
			free(args[i]);
		free(args);
	}
	}
	else
	{
		read = read_input(&input, &len);
		while (read != -1)
		{
			input[read - 1] = '\0';
			args = parse_input(input);
			if (args[0])
				execute_command(args, envp, input);
			for (i = 0; args[i]; i++)
				free(args[i]);
			free(args);
			read = read_input(&input, &len);
		}
	}
	free(input);
	return (0);
}