#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint - a function that prints all the elements of a listint_t list.
 * @h: a pointer to the head node of  a listint_t list.
 * Return: The number of nodes.
 */
size_t print_listint(const listint_t *h)
{
	size_t nodesCounted = 0;

	while (h)
	{
		nodesCounted++;
		printf("%d\n", h->n);
		h = h->next;
	}
	return (nodesCounted);
}
