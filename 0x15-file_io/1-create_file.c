#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"
#include <string.h>
/**
 * create_file - function that creates a file.
 * @filename: pointer 
 * @text_context: ......
 *
 * Return: 1 on success, -1 on failure (file can not be created,
 * file can not be written, write “fails”
 *
 */
int create_file(const char *filename, char *text_content)
{
	int d, write_status, close_status;
	mode_t file_permission = S_IRUSR | S_IWUSR;

	if (filename == NULL)
		return (-1);
	d = open(filename, O_WRONLY | O_CREAT | O_TRUNC, file_permission);
	if (d == -1)
		return (-1);
	if (text_content != NULL)
	{
		write_status = write(d, text_content, strlen(text_content));
		if (write_status == -1)
		{
			close(d);
			return (-1);
		}

	}
	close_status = -close(d);
	if (close_status == -1)
		return (-1);
	return (1);
}


