#include "main.h"

/**
 * This code converts binary digits to integers
 * @b: This is the parametre for our prototype
 * return: printed digits
 */

unsigned int binary_to_uint(const char *b)
{
    unsigned int result = 0;
    unsigned int bit_value = 1;

    if (b == NULL)
        return 0;

    // Calculate the length of the input string without using the standard library
    unsigned int length = 0;
    while (b[length] != '\0')
        length++;

    // Check for invalid characters in the string
    for (unsigned int i = 0; i < length; i++)
    {
        if (b[i] != '0' && b[i] != '1')
            return 0; // Invalid character found
    }

    // Convert binary string to unsigned int
    for (int i = length - 1; i >= 0; i--)
    {
        if (b[i] == '1')
            result += bit_value;
        bit_value <<= 1;
    }

    return result;
}
