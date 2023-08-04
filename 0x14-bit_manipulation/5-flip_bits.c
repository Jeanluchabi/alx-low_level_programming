#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * flip_bits - A function that returns the number of bits
 * you would need to flip to get from one number.
 * @n: the first number
 * @m: the second number
 * Return:  the number of bits  to be  flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int x, count = 0;
	unsigned long int ongoingBit;
	unsigned long int excludingBit = n ^ m;

	for (x = 63; x >= 0; x--)
	{
		ongoingBit = excludingBit >> x;

		if (ongoingBit & 1)
			count++;
	}
	return (count);
}
