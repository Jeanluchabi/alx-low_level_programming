#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * add_node -  adds a new node at the beginning of a list_t list.
 * @head: first node
 * @str: string to be added.
 * Return: he address of the new element, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_ *temp;
	int size = 0;

	temp = malloc(sizeof(list_t));
	if (tem == NULL)
		return (NULL);

	while (str[size])
		size++;

	temp->len = size;
	temp->str = strdup(str);
	temp->next = *head;
	*head = temp;
	return (temp);
}
