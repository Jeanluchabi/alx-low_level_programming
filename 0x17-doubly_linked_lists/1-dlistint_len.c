#include "lists.h"

/**
 * dlistint_len - This function Counts the number of elements
 * in a linked dlistint_t list.
 *
 * @h: The pointer to the head of the linked list.
 *
 * Return: The number of elements in the linked list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t counting = 0;

	while (h != NULL)
	{
		counting++;
		h = h->next;
	}
	return (counting);
}
