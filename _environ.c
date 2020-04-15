include "holberton.h"

/**
 * _environ - prints the environment
 *
 * Return: Always 0.
 */
int _environ(char *environ[])
{
    unsigned int i;

    i = 0;
    while (environ[i] != NULL)
    {
        _printf("%s\n", environ[i]);
        i++;
    }
    return (0);
}