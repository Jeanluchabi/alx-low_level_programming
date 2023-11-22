#include "lists.h"

/**
 * add_dnodeint - This function adds a new node at
 * the beginning of a dlistint_t list
 *
 * @head: The pointer to the head of the linked list
 * @n: The value to be assigned to the new node
 *
 * Return: An address of the new element,
 * or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *fresh_node;

	fresh_node = malloc(sizeof(dlistint_t));
	if (fresh_node == NULL)
		return (NULL);
	fresh_node->n = n;
	fresh_node->prev = NULL;
	fresh_node->next = *head;
	if (*head != NULL)
		(*head)->prev = fresh_node;
	*head = fresh_node;
	return (fresh_node);
}
