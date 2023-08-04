#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  get_bit - A  function that returns the value of a bit at a given index.
 *  @index:  the index, starting from 0 of the bit you want to get.
 *  @n: searching times
 *  Return:  value of the bit at index index or -1 if an error occured.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_num;

	if (index > 63)
		return (-1);
	bit_num = (n >> index) & 1;

	return (bit_num);
}
