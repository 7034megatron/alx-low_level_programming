#include "main.h"

void print_rev(char *s)
{
	int count = 0;
	while(*s != '\0')
	{
		s++;
		count++;
	}
	
	while(count != 0)
	{
		s--;
		count--;
		_putchar(*s);
	}
	_putchar('\n');
}
