#include <stdio.h>
int main()
{
    int i;
    char a[] = "";
    if (printf("%s", a))
        printf("The string is empty");
    else
        printf("The string is not empty");
    return 0;
}
/*
OUTPUT:
The string is not empty
*/