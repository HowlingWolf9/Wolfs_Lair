#include <stdio.h>
int main()
{
    int *ptr, a = 12;
    ptr = &a;
    *ptr = *ptr - 2**ptr;
    printf("%d, %d", *ptr, a);
    return 0;
}

/*
OUTPUT:
-12, -12
*/