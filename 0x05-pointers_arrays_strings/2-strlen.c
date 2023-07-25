#include "main.h"

int _strlen(char *s)
{
	int count = 0;
	while (*s != '\0')
	{
		s++;
		count++;
	}
return count;
}
