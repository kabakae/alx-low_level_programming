#include "main.h"

/**
 * get_endianness - checks if a machine is little or bid
 * Return: .........
 *
 */
int get_endianness(void)
{
	unsigned int x = 1;
	char *c = (char *)&x;

	return (*c);
}
