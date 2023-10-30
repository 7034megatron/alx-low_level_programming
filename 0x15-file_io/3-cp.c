#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - prints an error message to stderr
 *  and exits with a specified code.
 * @code: the exit code.
 * @msg: the error message.
 */
void error_exit(int code, const char *msg)
{
	dprintf(2, "%s\n", msg);
	exit(code);
}
/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
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
