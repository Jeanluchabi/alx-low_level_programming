#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_endianness - A  function to check if the machine is
 * a little or big endian.
 * Return: 0 for big and 1 for little.
 */
int get_endianness(void)
{
	unsigned int i = 0;
	char *c = (char *) &i;

	return ((int)*c);
}
