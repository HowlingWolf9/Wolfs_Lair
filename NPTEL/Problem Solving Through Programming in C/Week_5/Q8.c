#include <stdio.h>
int main()
{
  int num = 0;
  do{
    --num;
    printf("%d", num);
    num++;
  }while (num >= 0);
  return 0;
}
