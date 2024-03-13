#include <stdio.h>
#include "search_algos.h"

/* interpolation_search - A function to search for a value in a sorted 
 * array of integers using the Interpolation search algorithm.
 
 * array: A pointer to the first element of the array to search in.
 * size: The number of elements in the array.
 * value: The value to search for.
 * Return: It returns an integer, representing the index of 
 *         the first occurrence of value in array, 
 *         or -1 if value is not found or if the array is NULL.
 */

int interpolation_search(int *array, size_t size, int value) 
{
    if (array == NULL || size == 0)
        return -1;

    size_t low = 0;
    size_t high = size - 1;

    while (low <= high && value >= array[low] && value <= array[high]) {
        size_t pos = low + (((double)(high - low) / (array[high] - array[low])) * (value - array[low]));
        printf("Comparing with value at index %zu: %d\n", pos, array[pos]);

        if (array[pos] == value)
            return pos;

        if (array[pos] < value)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1; 
}

/* main - A function where the program execution starts.
 
 * Return: An integer value to the operating system
*/

int main() 
{
    int array[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    size_t size = sizeof(array) / sizeof(array[0]);
    int value = 13;

    int index = interpolation_search(array, size, value);

    if (index != -1)
        printf("Value %d found at index %d\n", value, index);
    else
        printf("Value %d not found\n", value);

    return 0;
}

