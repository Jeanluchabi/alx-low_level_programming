#include "search_algos.h"

#define PRINT_CHECKED(array, index) \
	(printf("Value checked array[%lu] = [%d]\n", (index), (array)[index]))

#define PRINT_NOT_IN_RANGE(index) \
	(printf("Value checked array[%lu] is out of range\n", (index)))

/**
 * interpolation_search - A function to search for a value in
 * a sorted array of integers using interpolation search

 * @array: A pointer to the first element of the array
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: If value is not present in array or array is NULL, return -1.
 * Otherwise, return the index where value is located.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0, high = size - 1, mid = 0;

	if (array == NULL || size == 0)
		return (-1);

	while (low <= high && value >= array[low] && value <= array[high])
	{
		mid = low + ((double)(high - low) / (array[high] - array[low])) *
			(value - array[low]);
		PRINT_CHECKED(array, mid);

		if (array[mid] == value)
			return (mid);

		if (array[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}

	PRINT_NOT_IN_RANGE(mid);

	return (-1);
}

