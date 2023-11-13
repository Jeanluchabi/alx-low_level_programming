#include "main.h"
#include <stdio.h>

/**
 * _puts - This function prints a string,
 * followed by a new line, to stdout
 * @str: The string to be printed
 * Return: void
 */

void _puts(char *str)

{
	int x = 0;

	while (str[x] != '\0')
	{
	putchar(str[x]);
	x++;
	}
	putchar('\n');
}
