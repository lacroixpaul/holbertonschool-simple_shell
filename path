#include "header.h"

int check_command_path(const char *cmd)
{
	char *path = getenv("PATH");
	char *token, full_path[1024];

	if (!path)
	{
		return (0);
	}

	token = strtok(path, ":");
	while (token)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", token, cmd);
		if(access(full_path, X_OK) == 0)
		{
			return (1);
		}
		token = strtok(path, ":");
	}
	return (0);
}
int main()
{
    char command[256];
    pid_t pid;
    int status;

    while (1)
    {
        printf("$ ");
        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            break; // Fin de l'entrée
        }

        // Supprimer le saut de ligne à la fin de la commande
        command[strcspn(command, "\n")] = '\0';

        // Vérifier si la commande existe dans le PATH
        if (!check_command_path(command))
        {
            printf("Commande non trouvée : %s\n", command);
            continue;
        }

        // Créer un processus enfant
        pid = fork();
        if (pid == 0)
        {
            // Enfant : exécuter la commande
            execlp(command, command, NULL);
            perror("Erreur lors de l'exécution");
            exit(EXIT_FAILURE);
        }
        else if (pid > 0)
        {
            // Parent : attendre l'enfant
            wait(&status);
        }
        else
        {
            perror("Erreur lors de fork");
        }
    }

    return 0;
}
