# C - Simple Shell FR

## Description
Le projet Simple Shell vise à créer un interpréteur de commandes basique, inspiré du shell Unix. Il permet d'exécuter des commandes simples, de gérer les répertoires et d'interagir avec les variables d'environnement.

## Commande de Compilation
Pour compiler le projet, utilisez la commande suivante :
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## Requirements
Système d'exploitation :
Unix/Linux

Compilateur :
gcc (GNU Compiler Collection)

Langage de programmation :
C

## Exemples

Compilation et exécution de commandes simples :

![Compilation et execution de commandes simples](https://i.ibb.co/WyXYvrT/Compilation-et-execution-de-commandes-simples.png)

Fonctionne de manière interactive et non interactive :

![Interactif et non interactif](https://i.ibb.co/QHQBjmk/Fonctionne-de-maniere-interactive-et-non-interactive.png)

## Man page
Lien du fichier MAN page :

https://github.com/lacroixpaul/holbertonschool-simple_shell/blob/main/man_1_simple_shell

## Testing 

Tests des fuites mémoires effectués avec : 
```
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind-out.txt ./hsh
```
Exemple de test mémoire :

![Test avec Valgrind](https://i.ibb.co/YbJdBPc/Test-valgrind.png)

Résultats :

![Résultat test Valgrind](https://i.ibb.co/6JcxvZX/Resultat-test-m-moire.png)

Tests du programme effectués avec des commandes avec et sans arguments, avec un PATH spécifié et non spécifié, avec des commandes et/ou arguments erronés.

Exemple :

![Test de commandes](https://i.ibb.co/JtqGX0r/Test-commandes.png)

## Flowchart

![Flowchart](https://image.noelshack.com/fichiers/2025/02/2/1736253331-flowchart-fr.jpg)

## Auteurs

- Tom Chaakni
- Paul Lacroix

# C - Simple Shell EN

## Description
The Simple Shell project aims to create a basic command interpreter, inspired by the Unix shell. It allows the execution of simple commands, managing directories, and interacting with environment variables.

## Compilation command
To compile the project, use the following command :
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## Requirements
Operating system :
Unix/Linux

Compilater :
gcc (GNU Compiler Collection)

Programmation language :
C

## Examples

Compilation and execution of simple commands :

![Compilation et execution de commandes simples](https://i.ibb.co/WyXYvrT/Compilation-et-execution-de-commandes-simples.png)

Works in both interactive and non-interactive modes :

![Interactif et non interactif](https://i.ibb.co/QHQBjmk/Fonctionne-de-maniere-interactive-et-non-interactive.png)

## Man page
Link to MAN page file :

https://github.com/lacroixpaul/holbertonschool-simple_shell/blob/main/man_1_simple_shell

## Testing 

Memories tests conducted with : 
```
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind-out.txt ./hsh
```
Example of memory test :

![Test avec Valgrind](https://i.ibb.co/YbJdBPc/Test-valgrind.png)

Results :

![Résultat test Valgrind](https://i.ibb.co/6JcxvZX/Resultat-test-m-moire.png)

Program tests were conducted with commands with and without arguments, with a specified and unspecified PATH, and with incorrect commands and/or arguments.

Example :

![Test de commandes](https://i.ibb.co/JtqGX0r/Test-commandes.png)

## Flowchart

![Flowchart](https://image.noelshack.com/fichiers/2025/02/2/1736253331-flowchart.jpg)

## Authors

- Tom Chaakni
- Paul Lacroix

