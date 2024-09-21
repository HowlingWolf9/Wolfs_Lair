#include <stdio.h>
#define A 5
#define B 8
#define C 2
int main()
{
    int (*x)[A][B][C];
    printf("%d", sizeof(*x));
    return 0;
}

/*
OUTPUT:
320
*/