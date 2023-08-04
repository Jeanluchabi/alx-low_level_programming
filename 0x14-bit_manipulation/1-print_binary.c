#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_binary - A function that prints the binary representation of a number.
 * @n: number to be printed
 */
void print_binary(unsigned long int n)
{
	unsigned long int prevNum;
	int a, count = 0;

	for (a = 63; a >= 0; a--)
	{
		prevNum = n >> a;

		if (prevNum & 1)
		{
			_putchar('1');
			count++;

		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}
