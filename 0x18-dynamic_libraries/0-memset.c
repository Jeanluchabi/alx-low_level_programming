#include "main.h"

/**
 * _memset - this function fills memory with constant byte
 * @n: The number of bytes of the memory
 * @s: The pointer
 * @b: The constant byte
 *
 * Return: The  pointer to the memory area s
 *
 */

char *_memset(char *s, char b, unsigned int n)

{
	unsigned int x;

	for (x = 0; x < n; x++)
	{
	s[x] = b;
	}
	return (s);
}
