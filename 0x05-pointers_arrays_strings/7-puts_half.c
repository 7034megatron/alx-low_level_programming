#include "main.h"

void puts_half(char *str)
{	
	int i;
	int start_index;
	char *tmp = str;
       	int length = _strlen(tmp);

    if (length % 2 == 0) {
        start_index = length / 2;
    } else {
        start_index = (length + 1) / 2;
    }
  
	for (i = start_index; i < length; i++) 
	{
        	_putchar(str[i]);
   	 }
    _putchar('\n');      
}
