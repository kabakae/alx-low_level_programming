#include "search_algos.h"

/**
 * linear_search - ........
 * @array: Apointer........
 * @size: ........
 * @value: ..........
 *
 *
 * Return: ......
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	/* check if the array is NULL */
	if (array == NULL)
		return (-1);
	/* iterate over each element */
	for (i = 0; i < size; i++)
	{
		/* Print the value being */
		printf ("Value checked array[%lu] = [%d]\n", (unsigned long)i, array[i]);

		/* if the value */
		if (array[i] == value)
			/* Return the index */
			return (i);
	}
	return -1;
	/* value not found return -1 */
}
