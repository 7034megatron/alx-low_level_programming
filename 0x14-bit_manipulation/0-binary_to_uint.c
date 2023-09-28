#include "main.h"

/**
 * This code converts binary digits to integers
 * @b: This is the parametre for our prototype
 * return: printed digits
 */

unsigned int binary_to_uint(const char *b)
{
    unsigned int result = 0;

    if (b == NULL)
        return (0);

    while (*b)
    {
        if (*b != '0' && *b != '1')
            return (0);

        result = (result * 2) + (*b - '0');
        b++;
    }

    return (result);
}





