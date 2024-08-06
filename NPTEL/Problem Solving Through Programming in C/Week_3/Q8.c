#include <stdio.h>
int main(){
	int a=10,b=6;
	if (a>b)
		if (b>0)
			printf("b is positive\n");
		else
			printf("b is non-positive\n");
	printf("a is greater than b\n");
	return 0;
}