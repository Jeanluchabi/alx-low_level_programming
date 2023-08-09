#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * read_textfile - A  function that reads a text file and prints it to
 * the POSIX standard output.
 * @filename: file being read
 * @letters: number of letters
 * Return: s the actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *pum;
	ssize_t fs;
	ssize_t n;
	ssize_t o;

	fs = open(filename, O_RDONLY);
	if (fs == -1)
		return (0);
	pum = malloc(sizeof(char) * letters);
	o = read(fs, pum, letters);
	n = write(STDOUT_FILENO, pum, o);

	free(pum);
	close(fs);
	return (n);
}
