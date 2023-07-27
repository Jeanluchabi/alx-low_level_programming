#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * list_len -  returns the number of elements in a linked list_t list.
 * @h: linked list
 * Return: a number of elements of a list
 */
size_t list_len(const list_t *h)
{
	size_t countedNumbers = 0;

	while (h)
	{
		h = h->next;
		countedNumbers++;
	}

	return (countedNumbers);
}
