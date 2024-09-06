#include <stdio.h>
int main()
{
  int a = 0, i, b;
  for (i = 0; i <= 2; i += 0.5)
  {
    a++;
    continue;
  }
  printf("%d", a);
  return 0;
}
