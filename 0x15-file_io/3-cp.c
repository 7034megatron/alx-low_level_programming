#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void error_exit(int code, const char *msg) {
    dprintf(STDERR_FILENO, "%s\n", msg);
    exit(code);
}

int main(int argc, char *argv[]) {
    if (argc != 3)
        error_exit(97, "Usage: cp file_from file_to");

    int fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
        error_exit(98, "Error: Can't read from file");

    int fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_to == -1)
        error_exit(99, "Error: Can't write to file");

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(fd_to, buffer, bytes_read);
        if (bytes_written == -1)
            error_exit(99, "Error: Can't write to file");
    }

    if (bytes_read == -1)
        error_exit(98, "Error: Can't read from file");

    if (close(fd_from) == -1)
        error_exit(100, "Error: Can't close fd");

    if (close(fd_to) == -1)
        error_exit(100, "Error: Can't close fd");

    return 0;
}
