#include <stdio.h>
void enqueue(int *queue, int size, int *rear)
{
	if (*rear>=(size-1))
		printf("OVERFLOW");
	else
	{
		printf("Enter Number:");
		scanf("%d",&queue[*rear]);
		(*rear)++;
	}
}
void dequeue(int *queue, int *front, int *rear)
{
	if (*rear<*front)
		printf("UNDERFLOW");
	else
	{
		queue[*front]='\0';
		(*front)++;
	}
}
void display(int *queue, int *front, int *rear)
{
	if (*rear>*front)
		for (int i=*front;i<*rear;i++)
			printf("[%d]",queue[i]);
	else
		printf("Queue Empty");
}
int main()
{
	int size,opt,front=0,rear=0;
	printf("Enter the size of the Queue:");
	scanf("%d",&size);
	int queue[size];
	while (1)
	{
		printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\nSelect the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				enqueue(queue,size,&rear);
				break;
			case 2:
				dequeue(queue,&front,&rear);
				break;
			case 3:
				display(queue,&front,&rear);
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