#include "main.h"
#include <stddef.h>

/**
 * _strstr - This function locates a substring
 * @needle: The first input substring
 * @haystack: The second input substring
 *
 * Return: The pointer to the beginning of
 * the located substring, otherwise NULL
 */

char *_strstr(char *haystack, char *needle)

{
	for (; *haystack != '\0'; haystack++)
	{
		char *f = haystack;
		char *s = needle;

		while (*f == *f && *s != '\0')
		{
			f++;
			s++;
		}
		if (*s == '\0')
			return (haystack);
	}
	return (NULL);
}
