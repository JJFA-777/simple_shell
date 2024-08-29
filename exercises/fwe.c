#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
	int i = 0, status;
	pid_t child_pid;

	while (i < 5)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Fork Error: ");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Exec error: ");
				return (2);
			}
		}
		wait(&status);
		i++;
	}
	return (0);
}
