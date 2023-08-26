#include "main.h"
#include <stdlib.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

/**
 * check_elf - a function to check if a file is an ELF file.
 * @e_id: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *e_id)
{
	int ind;

	for (ind = 0; ind < 4; ind++)
	{
		if (e_id[ind] != 127 &&
				e_id[ind] != 'E' &&
				e_id[ind] != 'L' &&
				e_id[ind] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - A function to print the magic numbers of an ELF header.
 * @e_id: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *e_id)
{
	int ind;

	printf("  Magic:   ");

	for (ind = 0; ind < EI_NIDENT; ind++)
	{
		printf("%02x", e_id[ind]);
		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - a function to print the class of an ELF header.
 * @e_id: A pointer to an array containing the ELF class.
 */
void print_class(unsigned char *e_id)
{
	printf("  Class:                             ");

	switch (e_id[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_id[EI_CLASS]);
	}
}

/**
 * print_data - A function  the data of an ELF header.
 * @e_id: A pointer to an array containing the ELF class.
 */
void print_data(unsigned char *e_id)
{
	printf("  Data:                              ");

	switch (e_id[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_id[EI_CLASS]);
	}
}

/**
 * print_version - A function the version of an ELF header.
 * @e_id: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *e_id)
{
	printf("  Version:                           %d",
	       e_id[EI_VERSION]);

	switch (e_id[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - a function  to prints the OS/ABI of an ELF header.
 * @e_id: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *e_id)
{
	printf("  OS/ABI:                            ");

	switch (e_id[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_id[EI_OSABI]);
	}
}

/**
 * print_abi - A function to printsthe ABI version of an ELF header.
 * @e_id: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *e_id)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * print_type - a function to print the type of an ELF header.
 * @e_typ: The ELF type.
 * @e_id: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int e_typ, unsigned char *e_id)
{
	if (e_id[EI_DATA] == ELFDATA2MSB)
		e_typ >>= 8;

	printf("  Type:                              ");

	switch (e_typ)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - a function to prints the entry point of an ELF header.
 * @e_begin: The address of the ELF entry point.
 * @e_id: A pointer to an array containing the ELF class.
 */
void print_entry(unsigned long int e_begin, unsigned char *e_id)
{
	printf("  Entry point address:               ");

	if (e_id[EI_DATA] == ELFDATA2MSB)
	{
		e_begin = ((e_begin << 8) & 0xFF00FF00) |
			  ((e_begin >> 8) & 0xFF00FF);
		e_entry = (e_begin << 16) | (e_begin >> 16);
	}

	if (e_id[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_id);
}

/**
 * close_elf - a function to close an ELF file.
 * @cl: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int cl)
{
	if (close(cl) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", cl);
		exit(98);
	}
}

/**
 * main - a function to display the information contained in the
 * ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *title;
	int x, y;

	x = open(argv[1], O_RDONLY);
	if (x == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	title = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(x);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	y = read(x, header, sizeof(Elf64_Ehdr));
	if (y == -1)
	{
		free(title);
		close_elf(x);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(title->e_id);
	printf("ELF Header:\n");
	print_magic(title->e_id);
	print_class(title->e_id);
	print_data(title->e_id);
	print_version(title->e_id);
	print_osabi(title->e_id);
	print_abi(title->e_id);
	print_type(title->e_typ, title->e_id);
	print_entry(title->e_begin, title->e_id);

	free(title);
	close_elf(x);
	return (x);
}
