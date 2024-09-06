#include <stdio.h>
int main()
{
  short int k = 1, j = 1;
  while (k <= 4 || j <= 3)
  {
    k=k+2;
    j+=1;
  }
  printf("%d, %d", k, j);
  return 0;
}
