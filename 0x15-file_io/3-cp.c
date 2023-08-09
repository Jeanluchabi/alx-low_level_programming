#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void close_file(int fs);
char *create_buffer(char *file);

/**
 * create_buffer - allocates 1024 bytes of a buffer.
 * @file: The name of file to store chars.
 * Return: A pointer to the allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: can't write to %s\n", file);
		exit(99);
	}
	return (buffer);
}

/**
 * close_file - closes file descriptors.
 * @fs: the file descriptor.
 */
void close_file(int fs)
{
	int x;

	x = close(fs);

	if (x == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't close fd %d\n", fs);
		exit(100);
	}
}

/**
 * main - copies the contents of a file to another file.
 * @argc: the number of arguments
 * @argv: An array of pointers
 * Return: 0 if it is succeded.
 */
int main(int argc, char *argv[])
{
	int fr, t, n, m;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	fr = open(argv[1], O_RDONLY);
	n = read(fr, buffer, 1024);
	t = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (fr == -1 || n == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		m = write(t, buffer, n);
		if (t == -1 || m == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);

			free(buffer);
			exit(99);
		}

		n = read(fr, buffer, 1024);
		t = open(argv[2], O_WRONLY | O_APPEND);

	}
	while (n > 0);
	{
		free(buffer);
		close_file(fr);
		close_file(t);
	}

	return (0);
}
