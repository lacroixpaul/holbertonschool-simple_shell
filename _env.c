#include "header.h"

/**
* _env - print the current environnement variable.
* @envp : environnement variable.
* Return : nothing.
**/

void _env(char *envp[])
{
	int i = 0;

	for (; envp[i] != NULL; i++)
	{
		printf("%s\n", envp[i]);
	}
}
