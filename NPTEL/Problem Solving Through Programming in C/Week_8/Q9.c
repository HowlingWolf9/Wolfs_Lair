#include <stdio.h>
int find (int x, int y)
{
    return ((x < y) ? 0 : (x-y));
}
int main()
{
    int a = 50;
    int b = 30;
    int result = find(a, find(a, b));
    printf("%d", result);
}
/*
OUTPUT:
30
(find(a, find(a, b)) returns the Minimum of a and b)
*/