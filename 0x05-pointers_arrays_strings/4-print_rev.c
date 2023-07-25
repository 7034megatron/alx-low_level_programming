#include "main.h"

void print_rev(char *s)
{
	int count = 0;
	while(*s != '\0')
	{
		s++;
		count++;
	}
	s--;
	while(count != 0)
	{
		s--;
		count--;
		_putchar(*s);
	}
	_putchar('\n');
}
