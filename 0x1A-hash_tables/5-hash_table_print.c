#include "hash_tables.h"

/**
 * hash_table_print - This function prints a hash table
 * @ht: The hash table to be printed
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *x_node;
	unsigned long int x;
	int first = 1;

	if (ht == NULL)
	{
		return;
	}
	printf("{");
	for (x = 0; x < ht->size; x++)
	{
		x_node = ht->array[x];
		while (x_node)
		{
			if (!first)
			{
				printf(", ");
			}
			printf("'%s': '%s'", x_node->key, x_node->value);
			first = 0;
			x_node = x_node->next;
		}
	}
	printf("}\n");
}
