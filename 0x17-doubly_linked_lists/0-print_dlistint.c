#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - A funtion to prints all the elements
 * of a dlistint_t list
 *
 * @h: The pointer to the head of the linked list
 * Return: A number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t counting = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		counting++;
	}
	return (counting);
}
