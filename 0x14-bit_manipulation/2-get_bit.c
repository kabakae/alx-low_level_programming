#include "main.h"

/**
 * get_bit - function that returns the value of a bit at a given index.
 * @n: number to search
 * @index: of the bit
 *
 * Return: the value of the bit at index index or -1
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	mask = 1ul << index;
	return ((n & mask) ? 1 : 0);

}
