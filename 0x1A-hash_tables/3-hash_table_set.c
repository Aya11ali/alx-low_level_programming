#include "hash_tables.h"

/**
 * hash_table_set - add item to hash table
 * @ht: hash table printer
 * @key: string key
 * @value: string value
 * Return: index of the key.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int k_indexx;
	int updated_or_addedd = 0;
	/*check validation*/
	if (ht == NULL || key == NULL || key[0] == '\0')
		return (0);

	/*get index*/
	k_indexx = key_index((unsigned char *)key, ht->size);

	updated_or_addedd = update_valuee(ht, key, value, k_indexx);
	if (updated_or_addedd == 0)
		updated_or_addedd = add_node_to_hash_table(ht, key, value, k_indexx);

	return (updated_or_addedd);
}

/**
 * add_node_to_hash_table - adds a node to a hash table
 *
 * @ht: pointer to the hash table
 * @key: key to add
 * @value: value to add
 * @k_index: index of the key in the hash table
 *
 * Return: 1 on success, 0 on failure
 */
int add_node_to_hash_table(hash_table_t *ht, const char *key,
						   const char *value, unsigned long int k_index)
{

	hash_node_t *h_node;
	/*allocat node*/

	h_node = malloc(sizeof(hash_node_t));
	if (h_node == NULL)
		return (0);

	h_node->key = strdup(key);
	if (h_node->key == NULL)
	{
		free(h_node);
		return (0);
	}
	h_node->value = strdup(value);
	if (h_node->value == NULL)
	{
		free(h_node->key);
		free(h_node);
		return (0);
	}

	if (ht->array[k_index])
	{
		h_node->next = ht->array[k_index];
		ht->array[k_index] = h_node;
	}
	else
	{
		ht->array[k_index] = h_node;
		h_node->next = NULL;
	}
	return (1);
}

/**
 * update_valuee - updates the value of a node in a hash table
 *
 * @ht: pointer to the hash table
 * @key: key of the node to update
 * @value: new value to set
 * @k_index: index of the key in the hash table
 *
 * Return: 1 on success, 0 on failure
 */
int update_valuee(hash_table_t *ht, const char *key,
				 const char *value, unsigned long int k_index)
{
	hash_node_t *currentt;

	if (ht->array[k_index] == NULL)
		return (0);
	currentt = ht->array[k_index];

	while (currentt)
	{
		if (strcmp(currentt->key, key) == 0)
		{
			free(currentt->value);
			currentt->value = strdup(value);
			if (currentt->value == NULL)
				return (0);
			return (1);
		}
		currentt = currentt->next;
	}
	return (0);
}
