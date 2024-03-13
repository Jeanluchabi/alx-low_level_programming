#include <math.h>
#include "search_algos.h"

/**
 * jump_search - This function performs a jump search 
 * to find a value in a sorted array.
 *
 * @array: Pointer to the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to look for.
 *
 * Return:
 * - The index of the first occurrence of 'value' in 'array'.
 * - (-1) if 'value' is not present in 'array'.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step, start = 0, end = 0;

	if (!array)
		return (-1);

	step = sqrt(size);

	while ((end < size) && (array[end] < value))
	{
		printf("Value checked array[%d] = [%d]\n", (int)end, array[end]);
		start = end;
		end += step;

		if (start >= size)
			return (-1);
	}
	printf("Value found between indexes [%d] and [%d]\n", (int)start, (int)end);
	end = (end >= size) ? size - 1 : end;

	for (; (start <= end) && (array[start] <= value); start++)
	{
		printf("Value checked array[%d] = [%d]\n", (int)start, array[start]);

		if (array[start] == value)
			return ((int)start);
	}

	return (-1);
}
