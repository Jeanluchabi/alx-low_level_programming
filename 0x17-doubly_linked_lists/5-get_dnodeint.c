#include "lists.h"

/**
 * get_dnodeint_at_index - This function returns the nth
 * node of a dlistint_t linked list
 *
 * @head: A pointer to the head of the linked list
 * @index: an index of the node to retrieve, starting from
 * Return: A pointer to the nth node, or NULL if not found
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current_node = head;
	unsigned int counting = 0;

	while (current_node != NULL)
	{
		if (counting == index)
			return (current_node);
		current_node = current_node->next;
		counting++;
	}
	return (NULL);
}
