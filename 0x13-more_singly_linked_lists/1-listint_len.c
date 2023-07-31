#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * listint_len - a function that will return the number
 * of elements in listint_t list.
 * @h: a pointere to the head
 * Return: The number of elements in listint_t list.
 */
size_t listint_len(const listint_t *h)
{
	size_t numberofNodes = 0;

	while (h != NULL)
	{
		numberofNodes++;
		h = h->next;
	}
	return (numberofNodes);
}
