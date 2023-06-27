#include "main.h"
/**
 * print_array - a function that prints n elements of an array
 * @a: arrayto be printed
 * @n: is the number of elements of the array to be printed
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (i == 0)
			printf("%d", a[i]);
		else
			printf(", %d", a[i]);
	}
	printf("\n");
}
