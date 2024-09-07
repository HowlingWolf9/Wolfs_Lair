#include <stdio.h>
int fibonacci (int n)
{
    switch (n)
    {
        default:
            return (fibonacci (n - 1) + fibonacci (n - 2));
        case 1:
        case 2:
    }
    return 1;
}
int main()
{
    int n = 46;
    int result = fibonacci (n);
    printf("%d", result);
}
/*
OUTPUT:
1836311903
(For some values of n, the environment will almost certainly exhaust its stack space before the calculation completes.)
*/