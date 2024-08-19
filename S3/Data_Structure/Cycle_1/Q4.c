#include <stdio.h>
#define SIZE 5
int top=0;
int stack[SIZE];
void push()
{
	if (top<SIZE)
	{
		printf("Enter the number:");
		scanf("%d",&stack[top]);
		(top)++;
	}
	else
		printf("Limit Exceeded\n");
}
void pop()
{
	if ((top)>0)
	{
		stack[top]='\0';
		(top)--;
	}
	else
		printf("Stack is empty\n");
}
void display()
{

	if ((top)>0)
		for(int i=(top-1);i>=0;i--)
			printf("[\t%d\t]\n",stack[i]);
	else
		printf("Stack is empty\n");
}
int main()
{
	int opt;
	while (1)
	{
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nSelect the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Program Exited Successfully\n");
				return 0;
			default:
				printf("Invalid operation\n");
				break;
		}
	}
}
