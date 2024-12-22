#include "header.h"

/**
* main - infinite boucle of the shell.
* @argc : number of arguments.
* @argv : string of arguments.
* @envp : environnement variable.
* Return: 0 in case of sucess.
**/

int main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	loop(envp);
	return (EXIT_SUCCESS);
}
