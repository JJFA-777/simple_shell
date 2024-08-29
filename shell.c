#include "shell.h"

/**
 *main - Entry point
 *
 *Return: Always 0 (success);
 *
 */

int main(void)
{
	char *line = NULL, *_argv[100];
	size_t n = 0;
	ssize_t num_char;
	const char *del = " \n";
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
			if (execve(_argv[0], _argv, NULL) == -1)
			{
				perror("Error executing command");
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
	}

	return (0);
}
