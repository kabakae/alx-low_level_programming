#include "main.h"

/**
 *main - .......
 * @argc: .....
 * @argv: ....
 * Return: .....
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	mode_t file_permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}
	fd_from = open_file(argv[1], O_RDONLY, 0);
	fd_to = open_file(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_permissions);
	copy_file(fd_from, fd_to);

	close_file(fd_from);
	close_file(fd_to);
	return (0);
}
/**
 * open_file - ........
 * @filename: .......
 * @flags: .....
 * @mode: ....
 * Return: .....
 */
int open_file(const char *filename, int flags, mode_t mode)
{
	int fd = open(filename, flags, mode);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open %s\n", filename);
		exit(98);
	}
	return (fd);
}
/**
 * copy_file - .......
 * @fd_from: ......
 * @fd_to: ....
 *
 * Return: .....
 */
void copy_file(int fd_from, int fd_to)
{
	char buffer[BUFFER_SIZE];
	ssize_t read_bytes, write_bytes;

	while ((read_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		write_bytes = write(fd_to, buffer, read_bytes);
		if (write_bytes == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file\n");
			exit(99);
		}
	}
	if (read_bytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file\n");
		exit(98);
	}
}
/**
 *close_file - .....
 * @fd: .....
 * Return: .....
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
