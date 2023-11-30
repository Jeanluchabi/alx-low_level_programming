#include "hash_tables.h"

/**
 * hash_djb2 - This function for implementation of the djb2 algorithm
 * @str: The string used to generate hash value
 *
 * Return: The value of hash
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int n;

	hash = 5381;
	while ((n = *str++))
	{
		hash = ((hash << 5) + hash) + n;
	}
	return (hash);
}
