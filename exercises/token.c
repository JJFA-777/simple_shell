#include <string.h>
#include <stdio.h>

/**
 *
 *
 */

int main(void)
{
	char str[] = "This is alx";
	const char *del = " ";
	char *retval;

	retval = strtok(str, del);

	while (retval != NULL)
	{
		printf("%s\n", retval);
		retval = strtok(NULL, del);
	}

	return (0);
}
