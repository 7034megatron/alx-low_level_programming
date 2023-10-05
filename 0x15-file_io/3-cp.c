#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - prints an error message to stderr and exits with a specified code.
 * @code: the exit code.
 * @msg: the error message.
 */
void error_exit(int code, const char *msg)
{
    dprintf(2, "%s\n", msg);
    exit(code);
}

/**
 * main - copies the content of a file to another file.
 * @argc: the number of arguments.
 * @argv: an array of argument strings.
 *
 * Return: 0 on success, otherwise exit with a specific code and print an error message.
 */
int main(int argc, char *argv[])
{
    int fd_from, fd_to, rd_count, wr_count;
    char buffer[BUFFER_SIZE];

    if (argc != 3)
        error_exit(97, "Usage: cp file_from file_to");

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
        error_exit(98, "Error: Can't read from file");

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
        error_exit(99, "Error: Can't write to file");

    while ((rd_count = read(fd_from, buffer, BUFFER_SIZE)) > 0)
    {
        wr_count = write(fd_to, buffer, rd_count);
        if (wr_count == -1)
            error_exit(99, "Error: Can't write to file");
    }

    if (rd_count == -1)
        error_exit(98, "Error: Can't read from file");

    if (close(fd_from) == -1)
        error_exit(100, "Error: Can't close fd");

    if (close(fd_to) == -1)
        error_exit(100, "Error: Can't close fd");

    return (0);
}
