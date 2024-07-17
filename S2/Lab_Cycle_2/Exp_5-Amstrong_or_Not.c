#include <stdio.h>
#include <math.h>

void main()
{
    int num,powr=0,pow_num,rem,amg=0;
    printf("Enter the number:");
    scanf("%d",&num);
    pow_num=num;
    while(pow_num>0)
    {
        powr++;
        pow_num=pow_num/10;
    }
    pow_num=num;
    while(pow_num>0)
    {
        rem=pow_num%10;
        amg=amg+pow(rem,powr);
        pow_num=pow_num/10;
    }
    if (num==amg)
        printf("Yes, Amstrong");
    else
        printf("Not Amstrong");
}