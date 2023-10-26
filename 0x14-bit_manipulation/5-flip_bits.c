#include "main.h"

/**
 * flip_bits -  returns the number of bit
 * s you would need to flip to get from one number to another
 * @n: first no.
 * @m: second number
 *
 *
 *
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int exclusive = n ^ m;
	unsigned int count = 0;

	while (exclusive > 0)
	{
		count += exclusive & 1;
		exclusive >>= 1;
	}
	return (count);
}
