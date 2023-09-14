#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - returns sum of parameters
 * @n: the number of parameter passed to the function
 * @...: variable number of parameter to calculate
 *
 * Return: .....
 *
 *
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int i, sum = 0;

	va_start(ap, n);
	for (i = 0; i < n; i++)
		sum += va_arg(ap, int);
	va_end(ap);
	return (sum);
}
