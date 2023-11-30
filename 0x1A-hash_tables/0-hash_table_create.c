#include "hash_tables.h"

/**
 * hash_table_create - This function creates a hash table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created hash table, or NULL on failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_t = NULL;
	unsigned long int x = 0;

	new_t = malloc(sizeof(hash_table_t));
	if (new_t == NULL)
		return (NULL);
	new_t->array = malloc(sizeof(hash_node_t *) * size);
	if (new_t->array == NULL)
	{
		free(new_t);
		return (NULL);
	}
	for (x = 0; x < size; x++)
	{
		new_t->array[x] = NULL;

	}
	new_t->size = size;
	return (new_t);
}
