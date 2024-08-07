#include <stdio.h>
void push(int *stack, int size, int *top)
{
	if (*top<size)
	{
		printf("Enter the number:");
		scanf("%d",&stack[*top]);
		(*top)++;
	}
	else
		printf("Limit Exceeded\n");
}
void pop(int *stack, int *top)
{
	if ((*top)>0)
	{
		stack[*top]='\0';
		(*top)--;
	}
	else
		printf("Stack is empty\n");
}
void display(int *stack, int* top)
{

	if ((*top)>0)
		for(int i=(*top-1);i>=0;i--)
			printf("[\t%d\t]\n",stack[i]);
	else
		printf("Stack is empty\n");
}
int main()
{
	int size,opt,top=0;
	printf("Enter the size of the stack:");
	scanf("%d",&size);
	int stack[size];
	while (1)
	{
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nSelect the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				push(stack,size,&top);
				break;
			case 2:
				pop(stack,&top);
				break;
			case 3:
				display(stack,&top);
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