#ifndef SHELL_H
#define SHELL_H


#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Prototypes */

char **_token(char *str, const char *delim, char *_argv[]);


#endif /*SHELL_H*/
