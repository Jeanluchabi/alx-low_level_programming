#include "search_algos.h"

/**
 * linear_search - A function to search for a value in an array
 *
 * @array: Pointer to the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to look for.
 *
 * Return:
 * - The index of the first occurrence of 'value' in 'array'.
 * - (-1) if 'value' is not present in 'array'.
 */
int linear_search(int *array, size_t size, int value)
{
	size_t x;

	for (x = 0; (x < size) && (array); x++)
	{
		printf("Value checked array[%d] = [%d]\n", (int)x, *(array + x));
		if (*(array + x) == value)
		{
			return (x);
		}
	}
	return (-1);
}
