#include "hash_tables.h"

/**
 * hash_table_get - This function retrieves the value associated with
 * a key in a hash table
 * @ht: A pointer to the hash table
 * @key: The key to get the value of a hash
 *
 * Return: If the key cannot be matched - NULL,
 * Otherwise - the value associated with key in ht
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *x_node;
	unsigned long int ind;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	ind = key_index((const unsigned char *)key, ht->size);
	if (ind >= ht->size)
		return (NULL);

	x_node = ht->array[ind];
	while (x_node && strcmp(x_node->key, key) != 0)
		x_node = x_node->next;

	return ((x_node == NULL) ? NULL : x_node->value);
}
