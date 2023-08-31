#include "main.h"

/**
 * binary_to_uint - converts a binary number to an
 * unsigned int.
 * @b: binary number.
 *
 * Return: unsigned int.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num;
	int length, base;

	if (!b)
		return (0);

	num = 0;

	for (length = 0; b[length] != '\0'; length++)
		;

	for (length--, base = 1; length >= 0; length--, base *= 2)
	{
		if (b[length] != '0' && b[length] != '1')
		{
			return (0);
		}

		if (b[length] & 1)
		{
			num += base;
		}
	}

	return (num);
}
