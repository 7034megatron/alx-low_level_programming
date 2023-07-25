#include "main.h"


void puts2(char *str) 
{
	int index = 0;
    while (str[index] != '\0' && str[index + 1] != '\0') {
     	_putchar(str[index);
        index += 2;
    }
    _putchar('\n');
}
