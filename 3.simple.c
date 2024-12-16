#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char str[] = "ls -l";
	char *token;
	char *tokenc;

	token = strtok(str, " ");
	while (token != NULL)
	{
		tokenc = malloc(strlen(token) + 1);
		if (tokenc == NULL)
		{
			write(1, "malloc failed", 13);
			return (1);
		}
		strcpy(tokenc, token);

		printf("token : %s\n", token);

		free(tokenc);

		token = strtok(NULL, " ");
	}
	return (0);
}
