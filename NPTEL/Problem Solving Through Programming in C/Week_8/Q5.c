#include <stdio.h>
int func (int x, int y)
{
    if (y == 0)
        return 0;
    if (y == 1)
        return x;
    return x + func (x, y-1);
}
int main()
{
    int x = 10;
    int y = 5;
    int result = func(x, y);
    printf("%d", result);
}
/*
OUTPUT:
50
("func" is a functinon which will return x * y where x and y are non-negative integers)
*/