#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_array - creates an array of chars, and initializes it with a char.
 * @size: array size.
 * @c: specified initial char
 * Return: pointer for array of chars.
 */
char *create_array(unsigned int size, char c)
{
	char *m;
	unsigned int i;

	if (size == 0)
		return (NULL);
	m = malloc(sizeof(*m) * size);
	if (m == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		m[i] = c;
	return (m);
}
