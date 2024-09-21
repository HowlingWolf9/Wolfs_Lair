#include <stdio.h>
void func(int x)
{
    x = 40;
}

int main()
{
    int y = 30;
    func(y);
    printf("%d", y);
    return 0;
}

/*
OUTPUT:
30
*/