#include "search_algos.h"

/**
 * print_array - This function prints an array of integers
 * @array: An array to print
 * @size: The size of array
 * return: void
 */
void print_array(int *array, size_t size)
{
	size_t x;

	printf("Searching in array:");
	for (x = 0; x < size; x++)
	{
		printf(" %d", array[x]);
		if (x != size - 1)
			printf(",");
	}
	printf("\n");
}

/**
 * binary_search - This function searches for a value in
 * a sorted array of integers using theBinary search algorithm

 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 * Return: An index where value is located, or -1 on failure
 */
int binary_search(int *array, size_t size, int value)
{
	size_t l, m, r;

	if (array != NULL && size > 0)
	{
		l = 0;
		r = size - 1;
		print_array(array + l, r + 1 - l);
		while (l < r)
		{
			m = (l + r) / 2;
			if (array[m] < value)
				l = m + 1;
			else if (array[m] > value)
				r = m;
			else
				return (m);
			print_array(array + l, r + 1 - l);
		}
	}
	return (-1);
}

/**
 * minimum_value - This function finds the minimum of two values
 * @a: The first value to compare
 * @b: The second value to compare
 * Return: The smaller of the two values, or a if equal
 */
size_t minimum_value(size_t a, size_t b)
{
	if (b < a)
		return (b);
	return (a);
}

/**
 * exponential_search - This function searches for a value in
 * a sorted array of integersusing the Exponential search algorithm

 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 * Return: The first index where value is located, or -1 on failure
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1, low;
	int r;

	if (array != NULL && size > 0)
	{
		while (bound < size && array[bound] < value)
		{
			printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
			bound *= 2;
		}
		low = bound / 2;
		bound = minimum_value(size - 1, bound);
		printf("Value found between indexes [%lu] and [%lu]\n", low, bound);
		r = binary_search(array + low, bound + 1 - low, value);
		if (r >= 0)
			return (r + low);
	}
	return (-1);
}
