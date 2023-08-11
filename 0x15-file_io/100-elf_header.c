#include "main.h"
#include <stdio.h>
#include <elf.h>
#include <stdlib.h>
#include <unistd.h>

void close_elf(int elf);
void print_magic(unsigned char *e_ident);
void check_elf(unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);

/**
 * check_elf - checks whether a file is ELF file.
 * @e_ident: a pointer to an array containing the ELF magic numbers.
 */
void check_elf(unsigned char *e_ident)
{
	int ind;

	for (ind = 0; ind < 4; ind++)
	{
		if (e_ident[ind] != 127 &&
			e_ident[ind] != 'E' &&
			e_ident[ind] != 'L' &&
			e_ident[ind] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}
/**
 * print_magic - prints the magic numbers of an ELF header.
 * @e_ident: pointer to an array
 */
void print_magic(unsigned char *e_ident)
{
	int index;

	printf("Magic: ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}
/**
 * print_class - prints the class of ELF header.
 * @e_ident: a pointer to an array.
 */
void print_class(unsigned char *e_ident)
{
	printf("Class: ");

	switch (e_ident[EI_CLASS])
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
		printf("unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * print_data - prints the data of ELF header.
 * @e_ident - a pointer to an array.
 */
void print_data(unsigned char *e_ident)
{
	printf("Data: ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, big endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}
}
/**
 * print_version - prints the version of an ELF header.
 * @e_ident: a pointer to an array
 */
void print_version(unsigned char *e_ident)
{
	printf("Version: %d", e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf("(current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}
/**
 * print_osabi - prints the OS/ABI of an ELF header.
 * @e_ident: a pointer to an array.
 */
void print_osabi(unsigned char *e_ident)
{
	printf("OS/ABI: ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABINONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABIHPUX:
		printf("UNIX - HP -UX\n");
		break;
	case ELFOSABINETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABILINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABISOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABIIRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABIFREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABITRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABIARM:
		printf("ARM\n");
		break;
	case ELFOSABISTANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}
/**
 * print_abi - prints the ABI version of an ELF header.
 * @e_ident: a pointer to an array.
 */
void print_abi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n",
			e_ident[EI_ABIVERSION]);
}

