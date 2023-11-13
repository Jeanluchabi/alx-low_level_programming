#include "main.h"

/**
 * _strcmp - This function compares two strings
 * @s1: The first string to be compared
 * @s2: The second string to be compared
 * Return: Integer greater than,
 * equal to or less than 0
 * according to the order of strings
 */

int _strcmp(char *s1, char *s2)

{
	while (*s1 && (*s1 == *s2))
	{
	s1++;
	s2++;
	}
	return (*s1 - *s2);
}
