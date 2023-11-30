#include "hash_tables.h"

/**
 * hash_table_delete - This function deletes a hash table
 * @ht: The hash table to be  deleted
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *n_node, *tmp;
	unsigned long int x;

	if (ht == NULL)
	{
		return;
	}
	for (x = 0; x < ht->size; x++)
	{
		n_node = ht->array[x];
		while (n_node)
		{
			tmp = n_node;
			n_node = n_node->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
		}
	}
	free(ht->array);
	free(ht);
}
