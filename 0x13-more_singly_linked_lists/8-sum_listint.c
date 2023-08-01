#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * sum_listint -  a function that returns the sum of all
 * the data (n) of a listint_t linked list.
 * @n: data to be returned
 * @head: pointer to the head of a listint_t linked list.
 * Return: 0 if  the list is empty.
 */
int sum_listint(listint_t *head)
{
	listint_t *Node = head;
	int sum = 0;

	while (Node)
	{
		sum += Node->n;
		Node = Node->next;
	}
	return (sum);
}
