#include "main.h"

/**
 * _strncpy - This function copies a string
 * @dest: the destination of a string
 * @src: the source of a string
 * @n: The number of bytes to be copies
 * Return:  The pointer to the destination string
 */

char *_strncpy(char *dest, char *src, int n)

{
	int x;

	for (x = 0; x < n && src[x] != '\0'; x++)
	{
	dest[x] = src[x];
	}
	for ( ; x < n; x++)
	{
	dest[x] = '\0';
	}
	return (dest);
}
