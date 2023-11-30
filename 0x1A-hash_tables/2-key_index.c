#include "hash_tables.h"

/**
 * key_index - This function  gives the index of a key
 * @key: The key
 * @size: The size of the array of the hash table
 * Return: The index of the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int value_of_hash;

	value_of_hash = hash_djb2(key);
	return (value_of_hash % size);
}
