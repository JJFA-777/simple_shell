#include <stdio.h>
#include <stdlib.h>

/**
*
*
*/

 int main(void)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t num_char;


	while (1)
	{
		printf("$ ");
		if ((num_char = getline(&line, &n, stdin)) != -1)
				printf("%s", line);
	}

	free(line);

	return(0);
}
