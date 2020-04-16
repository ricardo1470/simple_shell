#include "holberton.h"

int x(char **av, char **environ, char **array, char *buff, int *pt, int status)
{
pid_t child;
char errors[50];
int i = 0, execs = 0;

child = fork(), execs++;
if (child == 0)
{
	array[0] = list_path(array[0], environ);
	if (execve(array[0], array, environ) == -1)
	{	sprintf(errors, "%s: %d: %s: not found\n", av[0], execs, array[0]);
		write(STDERR_FILENO, errors, _strlen(errors)), free(buff);
		doublefree(array);
		i = 0;
		while (errors[i])
			errors[i++] = 0;
		exit(127);
	}
} else
	wait(&status), doublefree(array);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
	*pt = WEXITSTATUS(status);
	return (0);
}
