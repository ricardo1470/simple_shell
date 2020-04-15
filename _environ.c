#include "holberton.h"

/**
 * _environ - prints the environment
 *@environ: env 
 * Return: Always 0.
 */
int _environ(char *environ[])
{
    unsigned int i;

    i = 0;
    while (environ[i] != NULL)
    {
        write (STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write (STDOUT_FILENO,"\n", 1);
        i++;
    }
	
    return (0);
}