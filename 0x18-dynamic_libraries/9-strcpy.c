#include "main.h"

/**
 * _strcpy - This function copies the string pointed to by src
 * @dest: The destination value
 * @src: The source value
 * Return: The pointer to destination
 */

char *_strcpy(char *dest, char *src)

{
	int x;

	for (x = 0; src[x] != '\0'; x++)
	{
	dest[x] = src[x];
	}
	dest[x++] = '\0';
	return (dest);
}
