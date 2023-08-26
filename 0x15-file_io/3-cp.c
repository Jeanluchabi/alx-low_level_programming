#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * error_file - A function to  check if files can be opened.
 * @file_f: file_from.
 * @file_t: file_to.
 * @argv: arguments vector.
 * Return: no return.
 */
void error_file(int file_f, int file_t, char *argv[])
{
	if (file_f == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_t == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - A function to check the code
 * for Holberton School students.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int file_f, file_t, err_cls;
	ssize_t tchars, twr;
	char buff[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}
	file_f = open(argv[1], O_RDONLY);
	file_t = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(file_f, file_t, argv);

	tchars = 1024;
	while (tchars == 1024)
	{
		tchars = read(file_f, buff, 1024);
		if (tchars == -1)
			error_file(-1, 0, argv);
		twr = write(file_t, buff, tchars);
		if (twr == -1)
			error_file(0, -1, argv);
	}

	err_cls = close(file_f);
	if (err_cls == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_f);
		exit(100);
	}
	err_cls = close(file_t);
	if (err_cls == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_f);
		exit(100);
	}

	return (0);
}

