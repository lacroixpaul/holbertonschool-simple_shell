#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

ssize_t read_input(char **line, size_t *len);
int execute_command(char **args);
int main(void);
char **split_line(char *line);


#endif
