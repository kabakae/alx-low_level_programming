#include "main.h"
/**
 * leet - function that encodes a string into 1337.
 * letters a and A are replaced by 4.
 * letters e and E are replaced by 3
 * letters o and 0 are replaced by 0
 * letters t and T are replaced by 7
 * letters l and L are replaced by 1
 * @s: pointer to string.
 * Return: pointer to s.
 */
char *leet(char *s)
{
	int string_length, leetCount;
	char leetLetter[] = "aAeEO0tTlL";
	char leetNums[] = "4433007711";

	string_length = 0;
	while (s[string_length] != '\0')
	{
		leetCount = 0;
		while (leetCount < 10)
		{
			if (leetLetter[leetCount] == s[string_length])
			{
				s[string_length] = leetNums[leetCount];
			}
			leetCount++;
		}
		string_length++;
	}
	return (s);
}

