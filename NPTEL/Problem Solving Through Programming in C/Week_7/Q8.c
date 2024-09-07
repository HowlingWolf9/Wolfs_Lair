#include <stdio.h>
#include <string.h>
int main()
{
    char str1[20] = "hello", str2[20] = " world";
    printf("%s", strcpy(str2, strcat(str1, str2)));
    return 0;
}
/*
OUTPUT:
hello world
*/