#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read text file and print to STDOUT.
 * @filename: The name of the text file to be read.
 * @letters: The number of letters to be read and printed.
 *
 * Return: The actual number of bytes read and printed.
 *         0 when the function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    char *buf;
    ssize_t fd, t, w;

    /* Open the file for reading */
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);

    /* Allocate memory for the buffer */
    buf = malloc(sizeof(char) * letters);
    if (buf == NULL)
    {
        close(fd);
        return (0);
    }

    /* Read data from the file into the buffer */
    t = read(fd, buf, letters);
    if (t == -1)
    {
        free(buf);
        close(fd);
        return (0);
    }

    /* Write the data from the buffer to STDOUT */
    w = write(STDOUT_FILENO, buf, t);
    if (w == -1 || w != t)
    {
        free(buf);
        close(fd);
        return (0);
    }

    /* Clean up and return the actual number of bytes read and printed */
    free(buf);
    close(fd);
    return (w);
}
