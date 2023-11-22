#include "lists.h"

/**
 * add_dnodeint_end - This function adds a new node at
 * the end of a dlistint_t lis
 *
 * @head: The pointer to  the head of the linked list
 * @n: The value to be assigned to the new node
 *
 * Return: An address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *fresh_node, *tmp;

	fresh_node = malloc(sizeof(dlistint_t));
	if (fresh_node == NULL)
		return (NULL);
	fresh_node->n = n;
	fresh_node->next = NULL;
	if (*head == NULL)
	{
		fresh_node->prev = NULL;
		*head = fresh_node;
		return (fresh_node);
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = fresh_node;
	fresh_node->prev = tmp;
	return (fresh_node);
}
