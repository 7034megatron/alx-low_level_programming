#include "main.h"
#include <unistd.h>
/**
 * _putchar - The function writes c to stdout
 * @c: is the charecter that is printed to stdout
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
