#include "main.h"



/**
 * read_textfile - function that reads a text file and prints it
 * to the POSIX standard output
 * @filename: name of file to read
 * @letters: no. of letters to read
 *
 * Return: the actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;

	ssize_t n, r;
	char buffer[1024];

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	n = 0;
	while ((r = read(fd, buffer, sizeof(buffer))) > 0 && n < (ssize_t)letters)
	{
		ssize_t to_print = (r < (ssize_t)(letters - n)) ? r : (ssize_t)(letters) - n;
		ssize_t written = write(STDOUT_FILENO, buffer, to_print);

		if (written == -1 || written != to_print)

		{
			close(fd);
			return (0);
		}

		n += to_print;
	}

	close(fd);
	return (n);
}
