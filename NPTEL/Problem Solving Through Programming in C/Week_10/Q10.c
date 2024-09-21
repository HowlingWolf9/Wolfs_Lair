#include <stdio.h>
int main()
{
    char *s = "programming";
    char *p = s;
    printf("%c, %c", *(p + 3), s[3]);
    return 0;
}
/*
OUTPUT:
g, g
*/