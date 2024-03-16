#include "search_algos.h"


/**
  * advanced_binary_recursive - This fuction searches recursively for
  * a value in a sorted array of integers using binary search.

 * @array: A pointer to the first element of the [sub]array to search.
  * @left: The starting index of the [sub]array to search.
  * @right: The ending index of the [sub]array to search.
  * @value: The value to search for.
  *
  * Return: If the value is not present, -1.
  *         Otherwise, the index where the value is located.
  *
  * Description: Prints the [sub]array being searched after each change.
  */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t x;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (x = left; x < right; x++)
		printf("%d, ", array[x]);
	printf("%d\n", array[x]);

	x = left + (right - left) / 2;
	if (array[x] == value && (x == left || array[x - 1] != value))
		return (x);
	if (array[x] >= value)
		return (advanced_binary_recursive(array, left, x, value));
	return (advanced_binary_recursive(array, x + 1, right, value));
}



/**
 *advanced_binary -  This  function  searches for a
 * value in a sorted array of integers.
 *
 * @array: A pointer to the first element in the array
 * @size: The Size of the array to search in
 * @value: An  element to be searched
 * Return: return index of searched element
 */

int advanced_binary(int *array, size_t size, int value)
	{
		if (array == NULL || size == 0)
			return (-1);

		return (advanced_binary_recursive(array, 0, size - 1, value));
	}
