#include <stdio.h>
int main()
{
    int ary[2][3];
    ary[][] = {{1,2,3},{4,5,6}};
    printf("%d\n", ary[1][0]);
    return 0;
}
/*
OUTPUT:
:5:9: error: expected expression before ']' token
    5 |     ary[][] = {{1,2,3},{4,5,6}};
      |         ^

Build finished with error(s).
*/