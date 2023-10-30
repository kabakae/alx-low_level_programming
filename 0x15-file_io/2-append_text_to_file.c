#include "main.h"

/**
 * append_text_to_file - ...... 
 * @filename: ........
 * @text_content:......
 * Return: ......
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t text_length = 0;
	ssize_t write_result;

	if (filename == NULL)
		return (-1);
	if (text_content == NULL)
		return (1);
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
	       return (-1);

	while (text_content[text_length])


		text_length++;
	write_result = write(fd, text_content,(size_t)text_length);
	if (write_result == -1 || write_result != text_length)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (1);
}
