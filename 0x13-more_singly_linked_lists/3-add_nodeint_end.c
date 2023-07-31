#include <stdlib.h>
#include "lists.h"
#include <stdio.h>

/**
 * *add_nodeint_end -  a function that adds a new node
 * at the end of a listint_t list.
 * @head: a pointer to head of listint_t list.
 * @n: integer contained in node to be created
 * Return:  the address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newNode, *tail;

	newNode = malloc(sizeof(listint_t));

	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	newNode->next = NULL;

	if (*head == NULL)
		*head = newNode;

	else
	{
		tail = *head;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = newNode;
	}
	return (*head);
}
