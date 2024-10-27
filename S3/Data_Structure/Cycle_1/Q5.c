#include <stdio.h>
int A[20], size, front, rear;

void ENQUEUE(int item)
{
	if (rear == size - 1)
		printf("Queue overflow\n");
	else if (rear == -1)
	{
		front = 0;
		rear = 0;
		A[rear] = item;
	}
	else
	{
		rear++;
		A[rear] = item;
	}
}

void DEQUEUE()
{
	if (front == -1)
		printf("Queue is empty\n");
	else if (front == rear)
	{
		printf("Deleted item is %d\n", A[front]);
		rear = -1;
		front = -1;
	}
	else
	{
		printf("Deleted item is %d\n", A[front]);
		front++;
	}
}

void display()
{
	int i;
	if (front == -1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("The queue elements are \n");
		for (i = front; i <= rear; i++)
		{
			printf("%d\t", A[i]);
		}
	}
}

int main()
{
	int opt, item;
	rear = -1;
	front = -1;
	printf("Enter the size of Queue: \n");
	scanf("%d", &size);
	do
	{
		printf("\nMenu\n");
		printf("\n1.ENQUEUE\t 2.DEQUEUE \t 3.DISPLAY \t 4.EXIT");
		printf("\nEnter the option:");
		scanf("%d", &opt);
		switch (opt)
		{
			case 1:
				printf("Enter the item to be inserted: \n");
				scanf("%d", &item);
				ENQUEUE(item);
				display();
				break;
			case 2:
				DEQUEUE();
				display();
				break;
			case 3:
				display();
				break;
			case 4:
				break;
			default:
				printf(" \nInvaild choice!Please try again");
				break;
		}
	} while (opt != 4);
}