#include "search_algos.h"

/**
 * print_array - A function prints the contents of an array.
 *
 * @array: Pointer to the source array to print.
 * @l: Left index of the array.
 * @r: Right index of the array.
 */
void print_array(int *array, size_t l, size_t r)
{
	size_t i;

	if (array)
	{
		printf("Searching in array: ");
		for (i = l; i < l + (r - l + 1); i++)
			printf("%d%s", *(array + i), i < l + (r - l) ? ", " : "\n");
	}
}
/**
 * binary_search_index - A function to search for a value in a sorted array
 *
 * @array: Pointer to the array to search in.
 * @l: Left index of the array.
 * @r: Right index of the array.
 * @value: The value to look for.
 *
 * Return:
 * - The index of the first occurrence of 'value' in 'array'.
 * - (-1) if 'value' is not present in 'array'.
 */
int binary_search_index(int *array, size_t l, size_t r, int value)
{
	size_t m;

	if (!array)
		return (-1);
	print_array(array, l, r);
	m = l + ((r - l) / 2);
	if (l == r)
		return (*(array + m) == value ? (int)m : -1);
	if (value < *(array + m))
		return (binary_search_index(array, l, m - 1, value));
	else if (value == *(array + m))
		return ((int)m);
	else
		return (binary_search_index(array, m + 1, r, value));
}
/**
 * binary_search - This function searchs for a value in a sorted array using binary search.
 *
 * @array: Pointer to the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to look for.
 *
 * Return:
 * - The index of the first occurrence of 'value' in 'array'.
 * - (-1) if 'value' is not present in 'array'.
 */
int binary_search(int *array, size_t size, int value)
{
	return (binary_search_index(array, 0, size - 1, value));
}
