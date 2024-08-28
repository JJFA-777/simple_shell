#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/**
*
*/

int main(void)
{
	pid_t my_ppid, my_pid;

	my_pid = getpid();

	my_ppid = getppid();

	printf("Child id is %u\n", my_pid);
	printf("Parent id is %u\n", my_ppid);

	return (0);
}

