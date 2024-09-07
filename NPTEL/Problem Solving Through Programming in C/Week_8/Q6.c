#include <stdio.h>
void func(int n, int sum)
{
    int k = 0, j = 0;
    if (n == 0)
        return;
    k = n % 10;
    j = n / 10;
    sum = sum + k;
    func (j, sum);
    printf("%d,", k);
}
int main()
{
    int a = 2048, sum = 0;
    func (a, sum);
    printf("%d ", sum);
}
/*
OUTPUT:
2,0,4,8,0 
*/