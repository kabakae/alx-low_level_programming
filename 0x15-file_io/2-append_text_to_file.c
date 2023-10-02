#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"
#include <string.h>

/**
 *  append_text_to_file - function that appends text at the end of a file.
 * @filename: pointer
 * @text_content: .....
 *
 * Return: 1 on success and -1 on failure
 *
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int q, r, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	q = open(filename, O_WRONLY | O_APPEND);
	r = write(q, text_content, len);
	if (q == -1 || r == -1)
		return (-1);
	close(q);
	return (1);
}
