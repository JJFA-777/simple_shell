#include "shell.h"

/**
*
*
*
*/

char **_token(char *str, const char *delim, char *_argv[])
{
		int i = 0;
		char *token;

		token = strtok(str, delim);

		while (token != NULL)
		{
			_argv[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		_argv[i] = NULL;

		return (_argv);
}
