#include "main.h"
#include <stdio.h>


void print_array(int *a, int n) 
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf(a[i]);
		printf(',');
		printf(' ');
	}	
	_putchar('\n');
}
