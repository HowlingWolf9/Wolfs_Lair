/*
Experiment: 5

AIM:  Implement a Menu driven program to perform the following operations on Queue Data Structure using Arrays. 
(i) Inserting an element to the Queue. 
(ii) Deleting an element from the Queue. 
(iii) Display the contents of the Queue

ALGORITHM: main()
Step 01: START
Step 02: WHILE TRUE repeat steps 
Step 03: 	Read the option from the user, opt
Step 04:	SWITCH to opt
Step 05:		CASE 1: Call enqueue() function by passing queue, size and rear
Step 06:		CASE 2: dequeue() function by passing queue, front and rear
Step 07:		CASE 3: display() function by passing queue, front and rear
Step 08:		CASE 4: Print "Program Exited Successfully" and STOP
Step 09:		DEFAULT: Print "Invalid operation" and STOP
Step 10: STOP

ALGORITHM: enqueue(int *queue, int size, int *rear)
Step 01: START
Step 02: IF (*rear>=(size-1))
Step 03:	Print "OVERFLOW"
Step 04: ELSE
Step 05:	Read queue[*rear]
Step 06:	Increment *rear
Step 07: STOP

ALGORITHM: dequeue(int *queue, int *front, int *rear)
Step 01: START
Step 02: IF (*rear<*front)
Step 03:	Print "UNDERFLOW"
Step 04: ELSE
Step 05:	Set queue[*front] = '\0'
Step 06:	Increment *front by 1
Step 07: STOP

ALGORITHM: display(int *queue, int *front, int *rear)
Step 01: START
Step 02: IF (*rear>*front)
Step 03:	Initialize i = *front and repeat steps 04 to 05 until i < *rear
Step 04:		Print queue[i]
Step 05			Increment i by 1
Step 06: ELSE
Step 07: 	Print "Queue Empty"
Step 08: STOP
*/
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
/*
OUTPUT:
*/