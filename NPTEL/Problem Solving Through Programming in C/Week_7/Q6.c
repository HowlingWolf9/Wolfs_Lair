#include <stdio.h>
#include <string.h>
int main()
{
    char p[] = "assignment";
    char t;
    int i,j;
    for (i = 0, j = strlen(p); i<j; i++)
    {
        t = p[i];
        p[i] = p[j - i];
        p[j - i] = t;
    }
    printf("%s", p);
    return 0;
}
/*
OUTPUT:

*/