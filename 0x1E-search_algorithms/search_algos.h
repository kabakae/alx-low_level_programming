#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct akiplist_a - ......
 * @n: ..........
 * @index: .......
 * @next: .......
 *
 * @express: .........
 */
typedef struct akiplist_a
{
	int n;
	size_t index;
	struct akiplist_a *next;
	struct akiplist_a *express;
} akiplist_t;




int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
#endif
