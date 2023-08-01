#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * *get_nodeint_at_index -  returns the nth node of a listint_t linked list.
 * @head: pointer to the head of a listint_t linked list.
 * @index: index of node
 * Return: NULL if  the node does not exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *ongoing = head;
	unsigned int check;

	while (ongoing != NULL && check < index)
	{
		ongoing = ongoing->next;
		check++;
	}
	if (ongoing == NULL)
	{
		return (NULL);
	}
	return (ongoing);
}
