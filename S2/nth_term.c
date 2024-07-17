#include <stdio.h>
//Complete the following function.

int find_nth_term(int n, int a, int b, int c)
{
    int sum;
    
    if(n>3)
    {
		sum=a+b+c;
    	a=b;
   	 	b=c;
    	c=sum;
    	n--; 
        printf("a=%d,b=%d,c=%d,n=%d\n",a,b,c,n);
        find_nth_term(n, a, b, c);
    }
    else
    {
	return c;
	}
}

int main()
{
    int n, a, b, c;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
    printf("%d", ans); 
    return 0;
}