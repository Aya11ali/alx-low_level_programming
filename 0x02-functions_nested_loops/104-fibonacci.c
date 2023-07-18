#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned int a = 1, b = 2;

	printf("%u, %u", a, b);

	for (int i = 2; i < 98; i++)
	{
		unsigned int next = a + b;
		printf(", %u", next);
		a = b;
		b = next;
	}

	printf("\n");

	return (0);
}
