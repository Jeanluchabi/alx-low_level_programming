#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  pop_listint -  deletes the head node of a listint_t linked list,
 *  and returns the head node’s data (n).
 *  @head: pointer to the head of listint_t linked list.
 *  Return: 0 if the linked list is empty.
 */
int pop_listint(listint_t **head)
{
	listint_t *nextNode;
	int num;

	if (!head || !*head)
		return (0);

	num = (*head)->n;
	nextNode = (*head)->next;
	free(*head);
	*head = nextNode;

	return (num);
}
