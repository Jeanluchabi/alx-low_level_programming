#include "main.h"
#include <stdio.h>

/**
 * _strlen - This function returns the length of a string
 * @s: The pointer to the string
 *
 * Return: The length of a string
 *
 */

int _strlen(char *s)
{
	int length = 0;

	while (*s++)
	length++;
	return (length);
}
