#include "main.h"

/**
 * _strncat - This function concatenates two strings
 * @dest: the destination of the string
 * @src: the source of the string
 * @n: the number of bytes from source
 *
 * Return: The  pointer to the resulting string dest
 *
 */

char *_strncat(char *dest, char *src, int n)

{
	int dest_length = 0, x;

	while (dest[dest_length] != '\0')
	{
	dest_length++;
	}
	for (x = 0; x < n && src[x] != '\0'; x++)
	{
	dest[dest_length + x] = src[x];
	}
	dest[dest_length + x] = '\0';

	return (dest);
}
