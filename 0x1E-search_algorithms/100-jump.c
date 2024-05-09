#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers
 *               using the Jump search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The index of the first occurrence of value in array,
 *         or -1 if value is not present or array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return -1;

    size_t jump = sqrt(size);
    size_t prev = 0;
    size_t current = 0;

    printf("Value checked array[0] = [%d]\n", array[current]);
    while (current < size && array[current] < value)
    {
        prev = current;
        current += jump;
        if (current >= size)
            break;
        printf("Value checked array[%lu] = [%d]\n", current, array[current]);
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev, current);
    size_t i;
    for (i = prev; i < size && i <= current; i++)
    {
        printf("Value checked array[%lu] = [%d]\n", i, array[i]);
        if (array[i] == value)
            return i;
    }

    return -1;
}
