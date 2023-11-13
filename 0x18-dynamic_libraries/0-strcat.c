#include "main.h"

/**
 * _strcat - This function concatenates two strings
 * @dest:The  destination of a string
 * @src: The source of a string
 *
 * Return: The pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)

{
	int dest_length = 0, n;

	while (dest[dest_length] != '\0')
	dest_length++;

	for (n = 0; src[n] != '\0'; n++)
	dest[dest_length + n] = src[n];

	dest[dest_length + n] = '\0';

	return (dest);
}
