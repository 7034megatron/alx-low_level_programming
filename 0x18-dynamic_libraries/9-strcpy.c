#include "main.h"


char *_strcpy(char *dest, char *src) 
{
	int length = 0;
	int i;
	char *tmp = src;
	while ( *tmp != '\0' )
	{
		length++;
		tmp++;

	}

	for( i = 0; i <= length ; i ++) 
	{
		dest[i] = src[i];
	}

	return dest;
}
