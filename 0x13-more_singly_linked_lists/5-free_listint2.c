#include <stdlib.h>
#include "lists.h"
#include <stdio.h>

/**
 * free_listint2 - a function that frees a listint_t list.
 * and  sets the head to NULL.
 * @head: a pointer to the head of a listint_t list.
 */
void free_listint2(listint_t **head)
{
	listint_t *ongoing;

	while (head != NULL)
	{
		ongoing = *head;

		ongoing = (*head)->next;
		free(ongoing);

		*head = NULL;
	}
}
