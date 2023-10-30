#include "main.h"


/**
 * create_file - create ......
 * @filename: ........
 * @text_content: ......
 * Return: .....
 */
int create_file(const char *filename, char *text_content)
{
	int fd, res_write, len;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		len = 0;
		while (text_content[len] != '\0')
			len++;
		res_write = write(fd, text_content, len);
		if (res_write == -1 || res_write != len)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}
