#include "main.h"

/**
 * get_endianness - checks the system endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int value = 1;
	char *byte = (char *)&value;

	return ((int)*byte);
}
