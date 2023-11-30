#include "hash_tables.h"

/**
 * hash_table_set - This function adds an element to the hash table
 * @ht: The hash table
 * @key: The key
 * @value: The value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *fresh_node;
	char *valu_copy;
	unsigned long int index, x;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	valu_copy = strdup(value);
	if (valu_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	for (x = index; ht->array[x]; x++)
	{
		if (strcmp(ht->array[x]->key, key) == 0)
		{
			free(ht->array[x]->value);
			ht->array[x]->value = valu_copy;
			return (1);
		}
	}

	fresh_node = malloc(sizeof(hash_node_t));
	if (fresh_node == NULL)
	{
		free(valu_copy);
		return (0);
	}
	fresh_node->key = strdup(key);
	if (fresh_node->key == NULL)
	{
		free(fresh_node);
		return (0);
	}
	fresh_node->value = valu_copy;
	fresh_node->next = ht->array[index];
	ht->array[index] = fresh_node;

	return (1);
}
