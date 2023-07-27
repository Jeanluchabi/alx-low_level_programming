#include <stdio.h>
#include "lists.h"
#include <stdlib.h>

/**
 * print_list -  a function that prints all the elements of a list_t list.
 * @h: the list_t list.
 *
 * Return: The number of nodes in a.
 */
size_t print_list(const list_t *h)
{
	size_t nodesNumber = 0;

	while (h)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");

		else
			printf("[%d] %s\n", h->len, h->str);

		nodesNumber++;
		h = h->next;
	}

	return (nodesNumber);
}
