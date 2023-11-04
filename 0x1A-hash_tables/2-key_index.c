#include "hash_tables.h"
/**
 * key_index - get index of the key.
 * @key: string key
 * @size: The size of the array
 * Return: index of the key.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_keyy;

	hash_keyy = hash_djb2(key);

	return (hash_keyy % size);
}
