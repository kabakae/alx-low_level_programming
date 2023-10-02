#include <stdio.h>
#include <fcntl.h>  
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output.
 * @letters: .....
 * @filename: .....
 * Return: actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t tp, num_read, num_written;
	char *ptr;

	if (filename == NULL)
		return (0);
	tp = open(filename, O_RDONLY);
	if (tp == -1)
		return (0);
	ptr = malloc(sizeof(char) * letters);
	if (ptr == NULL)
	{
		close(tp);
		return (0);
	}
	num_read = read(tp, ptr, letters);
	if (num_read == -1)
	{
		free(ptr);
		close (tp);
		return (0);
	}
	num_written = write(STDOUT_FILENO, ptr, num_read);
	if (num_written == -1 || num_written != num_read)
	{
		free(ptr);
		close(tp);
		return (0);
	}
	free (ptr);
	close(tp);
	return (num_written);
}
