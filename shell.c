#include "shell.h"

/**
 *
 *
 */

int main(void)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t num_char;
	const char *del = " \n";
	char *_argv[100];
	int status;
	pid_t pid;


	while (1)
	{
		write(1, "#cisfun$ ", 10);

		num_char = getline(&line, &n, stdin);
		if (num_char == -1)
		{
			perror("Exit");
			free(line);
			break;
		}

		pid = fork();

		if (pid == -1)
		{
			perror("Error forking");
			free(line);
			break;
		}
		else if (pid == 0)
		{

			_token(line, del, _argv);

/*			i = 0;

			token = strtok(line, del);

			while (token != NULL)
			{
				_argv[i] = token;
				token = strtok(NULL, del);
				i++;
			}
			_argv[i] = NULL;
*/
			if (execve(_argv[0], _argv, NULL) == -1)
			{
				perror("Error executing command");
				exit (EXIT_FAILURE);
			}
		}
		else 
		{
			wait(&status);
		}

	}

	return(0);
}
