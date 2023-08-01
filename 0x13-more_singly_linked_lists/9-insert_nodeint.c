#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * listint_t *insert_nodeint_at_index -  inserts a new node
 * at a given position.
 * @head: pointer pointing to the head of linked list
 * @idx:the index of the list where the new node should be added.
 * @n: data to be inserted in new node.
 * Return: NULL if if it is not possible to
 * add the new node at index idx.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int a;
	listint_t *newNode;
	listint_t *currentNode = *head;

	newNode = malloc(sizeof(listint_t));

	if (!newNode || !head)
		return (NULL);

	newNode->n = n;
	newNode->next = NULL;

	if (idx == 0)
	{
		newNode->next = *head;
		*head = newNode;
		return (newNode);
	}


	for (a = 0; currentNode && a < idx; a++)
	{
		if (a == idx - 1)
		{
			newNode->next = currentNode->next;
			currentNode->next = newNode;
			return (newNode);
		}
		else
			currentNode = currentNode->next;
	}
	return (NULL);
}
