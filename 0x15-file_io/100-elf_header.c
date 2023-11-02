#include "main.h"

/**
 * print_error - ......
 * @msg: ......
 * Return: .......
 */
void print_error(char *msg)
{
	dprintf(2, "%s\n", msg);
	exit(98);
}
/**
 * print_elf_header - ........
 * @header: ......
 * Return: ......
 */
void print_elf_header(const Elf64_Ehdr *header)
{
	int i;
	char *ident = (char *)header->e_ident;

	printf("ELF Header:\n Magic: ");
	for (i = 0; i < 16; i++)
	{
		printf("%02x", ident[i]);
		if (i < 15)
			printf(" ");
	}

	printf("\n Class: %s\n", header->e_ident[EI_CLASS] == 1 ? "ELF32" : "ELF64");
	printf(" Data: %s\n", (header->e_ident[EI_DATA] == 1) ?
			"2' complement, little endian" : "2's complement, big endian");
	printf(" Version: %d (current)\n", header->e_ident[EI_VERSION]);
	printf(" OS/ABI: %s\n", header->e_ident[EI_OSABI] == ELFOSABI_SYSV ?
			"UNIX - System V" : "UNIX - NetBSD");
	printf(" ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
	printf(" Type: %s\n", header->e_type == ET_EXEC ? "EXEC (Executable file)" :
			"DYN (Shared Object file)");
	printf(" Entry point adress: 0x%lx\n", header->e_entry);
}
/**
 * main - ........
 * @argc: ........
 * @argv: ........
 *
 * Return: ......
 */

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error(strerror(errno));
	if (read(fd, &header, sizeof(header)) != sizeof(header))
		print_error("Unable to read ELF header");
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
		(header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3))
		print_error("Not an ELF file");
	print_elf_header(&header);
	close(fd);
	return (0);
}

