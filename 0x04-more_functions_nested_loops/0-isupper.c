#include "main.h"
/**
 * _isupper - checks for uppercase character
 *@c: int
 *Return: 1 if upper, 0 other
*/

int _isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}
