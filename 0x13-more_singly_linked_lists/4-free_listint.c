#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_listint - a fuction to free a listint_list.
 * @head: a pointer to the head of a listint_t list
 */
void free_listint(listint_t *head)
{
	listint_t *ongoing;

	while (head != NULL)
	{
		ongoing = head->next;
		free(head);
		head = ongoing;
	}
}
