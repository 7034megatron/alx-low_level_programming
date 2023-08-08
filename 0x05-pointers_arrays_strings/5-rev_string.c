#include "main.h"

/**
* rev_string - Reverses a string
* @s: Input string
* Return: String in reverse
*/
void rev_string(char*s) 
{
	int count = 0;
	char *end = s;

	while (*end != '\0') 
	{
		end++;
        	count++;
	}
	end--;

	while (s < end) 
	{
        	char temp = *s;
        	*s = *end;
        	*end = temp;
		s++;
        	end--;
    	}
}
