#include "main.h"

#include <limits.h>


/**
 * _atoi - This function converts a string to an integer
 *
 * @s: the string to be converted
 *
 * Return: The value of integer of string
 *
 */

int _atoi(char *s)

{
	int a = 0;
	unsigned int nit = 0;
	int mint = 1;
	int isit = 0;

	while (s[a])
	{
	if (s[a] == 45)
	{
	mint *= -1;
	}
	while (s[a] >= 48 && s[a] <= 57)
	{
	isit = 1;
	nit = (nit * 10) + (s[a] - '0');
	a++;
	}
	if (isit == 1)
	{
	break;
	}
	a++;
	}
	nit *= mint;
	return (nit);
}
