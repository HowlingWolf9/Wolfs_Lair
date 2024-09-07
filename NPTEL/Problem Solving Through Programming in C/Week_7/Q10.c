#include <stdio.h>
#include <ctype.h>
int main()
{
    int i = 0;
    char c;
    char str[] = "Programming Language";
    while (str[i] != ' ')
    {
        putchar (toupper(str[i]));
        i++;
    }
    return 0;
}
/*
OUTPUT:
PROGRAMMING
*/