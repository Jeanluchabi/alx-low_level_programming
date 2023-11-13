#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - This function searches a string
 * for any of a set of bytes
 *
 * @s: The string to be searched
 * @accept: The input value
 *
 * Return: The pointer to the byte in s
 * that matches one of the bytes in accept
 */

char *_strpbrk(char *s, char *accept)

{
	int n, m;

	for (n = 0; s[n] != '\0'; n++)
	{
	for (m = 0; accept[m] != '\0'; m++)
	{
	if (s[n] == accept[m])
	{
	return (s + n);
	}
	}
	}
	return (NULL);
}
