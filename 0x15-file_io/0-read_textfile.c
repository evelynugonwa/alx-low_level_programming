/*
 * File: 0-read_textfile.c
 * Auth: Dr Marcus.
 */
#include "main.h"
#include <stdlib.h>

/**
 *read_textfile- Read text file print to STDOUT
 *@filename: A pointer to the name of the file.
 *@letters: The number of letters the functionshould read and print
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}




