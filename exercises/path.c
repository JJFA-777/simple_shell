#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

 /**
 *
 *
 */

 int _which(char *filename)
 {
	char *path, *dir, *full_path;
    char *path_copy;
    size_t len;

    /* Get the PATH environment variable */
    path = getenv("PATH");
    if (path == NULL)
    {
        fprintf(stderr, "Error: PATH variable not found\n");
        return (1);
    }

    /* Duplicate the PATH so we can tokenize it */
    path_copy = strdup(path);
    if (path_copy == NULL)
    {
        perror("Error duplicating PATH");
        return (1);
    }

    /* Tokenize the PATH by ":" */
    dir = strtok(path_copy, ":");
    while (dir != NULL)
    {
        /* Allocate memory for the full path */
        len = strlen(dir) + strlen(filename) + 2;  /* +2 for "/" and null terminator */
        full_path = malloc(len);
        if (full_path == NULL)
        {
            perror("Error allocating memory");
            free(path_copy);
            return (1);
        }

        /* Construct the full path */
        snprintf(full_path, len, "%s/%s", dir, filename);

        /* Check if the file is executable */
        if (access(full_path, X_OK) == 0)
        {
            printf("%s\n", full_path);
            free(full_path);
            free(path_copy);
            return (0);
        }

        /* Free the allocated memory and continue */
        free(full_path);
        dir = strtok(NULL, ":");
    }

    /* If the file wasn't found */
    printf("%s not found in PATH\n", filename);
    free(path_copy);
    return (1);
}
	
 /**
 * main - Entry point.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
    int i;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
        return (1);
    }

    /* Iterate through each file provided in the arguments */
    for (i = 1; i < argc; i++)
    {
        _which(argv[i]);
    }

    return (0);
}
