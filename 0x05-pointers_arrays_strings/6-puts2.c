#include "main.h"
/**
 * puts2 - function should print only one character out of two
 * starting with the first one
 * @str: input
 * Return: print
 */
void puts2(char *str)
{
	int index = 0;
	
	while (str[index] != '\0' && str[index + 1] != '\0') 
	{
     		_putchar(str[index]);
        	index += 2;
	}	

    	if (str[index] != '\0') 
    	{
		_putchar(str[index]);
	}
	_putchar('\n');
}
