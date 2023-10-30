#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void error_exit(int code, const char *file, const char *msg) {
    dprintf(STDERR_FILENO, msg, file);
    exit(code);
}

int main(int argc, char *argv[]) {
    if (argc != 3)
        error_exit(97, NULL, "Usage: cp file_from file_to\n");

    const char *file_from = argv[1];
    const char *file_to = argv[2];

    int fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1)
        error_exit(98, file_from, "Error: Can't read from file %s\n");

    int fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_to == -1)
        error_exit(99, file_to, "Error: Can't write to file %s\n");

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(fd_to, buffer, bytes_read);
        if (bytes_written == -1)
            error_exit(99, file_to, "Error: Can't write to file %s\n");
    }

    if (bytes_read == -1)
        error_exit(98, file_from, "Error: Can't read from file %s\n");

    if (close(fd_from) == -1)
        error_exit(100, NULL, "Error: Can't close fd %d\n");

    if (close(fd_to) == -1)
        error_exit(100, NULL, "Error: Can't close fd %d\n");

    return 0;
}
