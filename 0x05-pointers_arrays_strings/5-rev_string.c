#include "main.h"

void rev_string(char *s) {
    

    int count = 0;
    char *end = s;

   
    while (*end != '\0') {
        end++;
        count++;
    }
    end--;

    while (s < end) {
        char temp = *s;
        *s = *end;
        *end = temp;

        s++;
        end--;
    }
}
