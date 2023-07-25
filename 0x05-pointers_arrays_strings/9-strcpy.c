#include "main.h"


char *_strcpy(char *dest, char *src) 
{
	int length;
	int i;
	char *tmp = src;
	while ( *tmp != '\0' )
	{
		length++;
		tmp++;

	}

	for( i = 0; i < length + 1; i ++) 
	{
		dest[i] = src[i];
	}

	return dest;
}
