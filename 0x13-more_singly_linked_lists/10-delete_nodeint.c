#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  delete_nodeint_at_index - a function that deletes the node
 *  at index index of a listint_t linked list.
 *  @head: pointer to the head of a listint_t linked list.
 *  @index: index of of the node to be deleted
 *  Return: 1  if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int x = 0;
	listint_t *Node = *head;
	listint_t *currentNode = NULL;

	if (*head != NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(Node);
		return (1);
	}

	while (x < index - 1)
	{
		if (!Node || !(Node->next))
			return (-1);
		Node = Node->next;
		x++;
	}
	currentNode = Node->next;
	Node->next = currentNode->next;
	free(currentNode);

	return (1);
}
