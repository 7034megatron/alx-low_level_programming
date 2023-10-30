#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * append_text_to_file - appends text to the end of a file.
 * @filename: the name of the file.
 * @text_content: the NULL-terminated string to add at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, result, len = 0;

	if (filename == NULL)
	return (-1);

	if (text_content == NULL)
	return (1);

	while (text_content[len])
	len++;

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
	return (-1);

	result = write(fd, text_content, len);
	if (result == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
