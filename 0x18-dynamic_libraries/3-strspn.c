#include "main.h"

/**
 * _strspn - This function calculates the length of
 * the initial segment of a string
 * @s: The input string
 * @accept: The characters to match
 *
 * Return: Always 0 if it Succeds
 */

unsigned int _strspn(char *s, char *accept)

{
	unsigned int x = 0;
	int y;

	while (*s)
	{
	for (y = 0; accept[y]; y++)
	{
	if (*s == accept[y])
	{
	x++;
	break;
	}
	else if (accept[x + 1] == '\0')
	return (x);
	}
	s++;
	}
	return (x);
}
