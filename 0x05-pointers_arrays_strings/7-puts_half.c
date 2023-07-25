#include "main.h"

void puts_half(char *str)
{
	char *tmp = str;
       	int length = _strlen(tmp);
	int start_index;

    if (length % 2 == 0) {
        start_index = length / 2;
    } else {
        start_index = (length + 1) / 2;
    }
    	int i;
	for (i = start_index; i < length; i++) 
	{
        	_putchar(str[i]);
   	 }
    _putchar('\n');      
}
