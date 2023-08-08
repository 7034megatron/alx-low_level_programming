#include "main.h"

/**
* swap_int - This function updates value of a pointer
* @a: integer
* @b: integer
* Description: his function takes an integer and changes it to 98
*/
void swap_int(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
