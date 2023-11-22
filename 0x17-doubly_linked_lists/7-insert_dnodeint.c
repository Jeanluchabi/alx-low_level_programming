#include "lists.h"

/**
 * insert_dnodeint_at_index - This function inserts
 * a new node at a given position
 *
 * @h: A pointer to the pointer to the head of the linked list
 * @idx: An index of the list where the new node
 * should be added (starting from 0)
 * @n: A value to be assigned to the data of the new node
 * Return: An address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *fresh_node, *current_node = *h;
	unsigned int x = 0;

	if (h == NULL)
		return (NULL);
	fresh_node = malloc(sizeof(dlistint_t));
	if (fresh_node == NULL)
		return (NULL);
	fresh_node->n = n;
	if (idx == 0)
	{
		fresh_node->next = *h;
		fresh_node->prev = NULL;
		if (*h != NULL)
			(*h)->prev = fresh_node;
		*h = fresh_node;
		return (fresh_node);
	}
	while (current_node != NULL)
	{
		if (x == idx - 1)
		{
			fresh_node->next = current_node->next;
			fresh_node->prev = current_node;
			if (current_node->next != NULL)
				current_node->next->prev = fresh_node;
			current_node->next = fresh_node;
			return (fresh_node);
		}
		current_node = current_node->next;
		x++;
	}
	free(fresh_node);
	return (NULL);
}
