#include "main.h"


void rev_string(char *s) 
{
	int count = 0;
        while(*s != '\0')
        {
                s++;
                count++;
        }

	char newS[count + 1];
       	for ( int i = 0; i < count; i++)
	{
		s--;
		news[i] = *s;
	}	
	newS[count] = '\0';
	s = newS;
}
