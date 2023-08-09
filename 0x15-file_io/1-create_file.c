#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_file - A function that creates a file.
 * @filename: The name of file to be created.
 * @text_content:  a NULL terminated string to write to the file.
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int rt, x, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	rt = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	x = write(rt, text_content, len);

	if (rt == -1 || x == -1)
		return (-1);
	close(rt);
	return (1);
}
