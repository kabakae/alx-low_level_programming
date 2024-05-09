#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array of integers
 *                        using the Interpolation search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The index of the value in the array, or -1 if not found
 */
int interpolation_search(int *array, size_t size, int value)
{
    size_t l = 0, r = size - 1;

    if (array == NULL || size == 0)
        return (-1);

    while (l <= r && value >= array[l] && value <= array[r])
    {
        size_t pos = l + (((double)(r - l) / (array[r] - array[l])) * (value - array[l]));

        printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

        if (array[pos] == value)
            return (pos);
        
        if (array[pos] < value)
            l = pos + 1;
        else
            r = pos - 1;
    }

    printf("Value checked array[%lu] is out of range\n", l);
    return (-1);
}
