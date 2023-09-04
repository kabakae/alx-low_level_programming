#include "main.h"
#include <stdlic.h>

/**
 * create_array - creates array of chars
 * @size: size of the array
 * @c: char to fill int the array
 *
 * Return: array filled
 */
char *create_array(unsigned int size, char c);
{
	unsigned int i;
	char *s;

	if (size == 0)
		return (NULL);
	s = malloc(size * sizeof(char));
	if (s == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		s[i] = c;
	}
	return (s);
}
