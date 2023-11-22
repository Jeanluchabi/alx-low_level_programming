#include "lists.h"

/**
 * delete_dnodeint_at_index - This function deletes
 * the node at a certain index
 * @head: A pointer to the pointer to the head of the linked list
 * @index: An index of the node to be deleted (starting from 0)
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current_node = *head;
	unsigned int x = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = current_node->next;
		if (current_node->next != NULL)
			current_node->next->prev = NULL;
		free(current_node);
		return (1);
	}

	while (current_node != NULL)
	{
		if (x == index)
		{
			if (current_node->prev != NULL)
				current_node->prev->next = current_node->next;
			if (current_node->next != NULL)
				current_node->next->prev = current_node->prev;
			free(current_node);
			return (1);
		}
		current_node = current_node->next;
		x++;
	}

	return (-1);
}
