#include "main.h"

/**
 * print_binary - Converts an integer into binary
 * @n: number to print in binary
 * Return: Print the binary representation of a number
 */

void print_binary(unsigned long int n)
{
    int bit, flag = 0;

    if (n == 0)
    {
        _putchar('0');
        return;
    }

    for (bit = (sizeof(unsigned long int) * 8) - 1; bit >= 0; bit--)
    {
        if ((n >> bit) & 1)
        {
            _putchar('1');
            flag = 1;
        }
        else if (flag)
        {
            _putchar('0');
        }
    }
}
int _putchar(char c)
{
    return write(1, &c, 1);
}
