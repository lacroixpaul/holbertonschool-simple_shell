#include "haeder.h"

int execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0) // Processus enfant
	{
	if (execve(args[0], args, environ) == -1)
	{
		perror("hsh");
		exit(EXIT_FAILURE);
	}
	}
	else if (pid < 0) // Échec de fork
	{
		perror("Fork failed");
		return -1;
	}
	else // Parent
	{
		wait(&status);
	}
	return (0);
}