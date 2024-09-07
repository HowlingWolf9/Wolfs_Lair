#include <stdio.h>
int main()
{
    {
        int a = 70;
    }
    {
        printf("%d", a);
    }
    return 0;
}
/*
OUTPUT:
:8:22: error: 'a' undeclared (first use in this function)
    8 |         printf("%d", a);
      |                      ^
:8:22: note: each undeclared identifier is reported only once for each function it appears in

Build finished with error(s).
*/