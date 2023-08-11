#include <stdio.h>
#include <ctype.h>
/**
 *
 *Description: 'print_alphabet' 
 *main -Entry point
 *
 * Return: Always 0 (success)
 */

int main(void)
{
int lowerCase = 'a';
while (lowerCase <= 'z')
{
putchar(lowerCase);
lowerCase += 1;
}
putchar('\n');
return (0);
}
