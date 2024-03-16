#include "search_algos.h"

/**
 * linear_skip - This function searches for an algorithm in
 * a sorted singly linked list of integers using linear skip.

 * @list: A pointer to the  head of the linked list to search.
 * @value: The value to search for.
 * Return: If the value is not present or the head of the list is NULL, NULL.
 *         Otherwise, a pointer to the first node where the value is located.
 * Description: Prints a value every time it is compared in the list.
 *              Uses the square root of the list size as the jump step.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *t_node, *jump;

	if (list == NULL)
		return (NULL);

	for (t_node = jump = list; jump->next != NULL && jump->n < value;)
	{
		t_node = jump;
		if (jump->express != NULL)
		{
			jump = jump->express;
			printf("Value checked at index [%ld] = [%d]\n",
				jump->index, jump->n);
		}
		else
		{
			while (jump->next != NULL)
				jump = jump->next;
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			t_node->index, jump->index);

	for (; t_node->index < jump->index && t_node->n < value;
			t_node = t_node->next)
		printf("Value checked at index [%ld] = [%d]\n", t_node->index, t_node->n);
	printf("Value checked at index [%ld] = [%d]\n", t_node->index, t_node->n);

	return (t_node->n == value ? t_node : NULL);
}
