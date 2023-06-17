#include <stdio.h>

/**
 * main - Prints the alphabet
 *
 * Rturn: Always 0 (Success)
 */
int main(void)
{
	char alp[26] = "abcdefghijklmnopqestuvwxyz";
	int i;
	for (i =0; i< 26; i++)
	{
		putchar(alp[i]);
	}
	putchar('\n);
	return (0);
}
