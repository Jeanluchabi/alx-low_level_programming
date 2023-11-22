#include "lists.h"

/**
 * sum_dlistint - This function eturns the sum of all data value
 * @head: A pointer to the head of the linked list
 * Return: A sum of all data values, or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int result = 0;
	dlistint_t *current_node = head;

	while (current_node != NULL)
	{
		result += current_node->n;
		current_node = current_node->next;
	}
	return (result);
}
