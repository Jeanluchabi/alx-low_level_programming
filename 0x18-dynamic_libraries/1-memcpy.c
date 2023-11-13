#include "main.h"

/**
 * _memcpy - This function copies memory area
 * @src: The source of memory area
 * @dest: The destination of memory area
 * @n: the number of bytes to be copied
 *
 * Return: The pointer to dest
 *
 */

char *_memcpy(char *dest, char *src, unsigned int n)

{
	unsigned int x;

	for (x = 0; x < n; x++)
	{
	dest[x] = src[x];
	}
	return (dest);
}
