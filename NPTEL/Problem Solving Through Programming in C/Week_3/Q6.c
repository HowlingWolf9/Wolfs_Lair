#include <stdio.h>
int main(){
	int x=1,y=0;
	if (x&&y){
		printf("Both are true\n");
	}else{
		printf("At least one is false\n");
	}
	return 0;
}