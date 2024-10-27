#include <stdio.h>
int A[20], size, front, rear;

void ENQUEUE_CQ(int item)
{
    if (((rear + 1) % size) == front)
        printf("Queue is Full ,insertion is not possible\n");
    else if (rear == -1)
    {
        front = 0;
        rear = 0;
        A[rear] = item;
    }
    else
    {
        rear = (rear + 1) % size;
        A[rear] = item;
    }
}

void DEQUEUE_CQ()
{
    if (front <= -1)
        printf("Queue is empty\n");
    else if (front == rear)
    {
        printf("Deleted item is %d\n", A[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("Deleted item is %d \n", A[front]);
        front = (front + 1) % size;
    }
}

void DISPLAY()
{
    int i;
    if (front == -1)
        printf("Queue is empty\n");
    else if (front <= rear)
    {
        for (i = front; i <= rear; i++)
            printf("%d\t", A[i]);
    }
    else
    {
        for (i = front; i <= size - 1; i++)
            printf("%d\t", A[i]);
        for (i = 0; i <= rear; i++)
            printf("%d \t", A[i]);
    }
}
int main()
{
    int opt, item;
    rear = -1;
    front = -1;
    printf("Enter the size of circular queue: \n");
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
                ENQUEUE_CQ(item);
                DISPLAY();
                break;
            case 2:
                DEQUEUE_CQ();
                DISPLAY();
                break;
            case 3:
                DISPLAY();
                break;
            case 4:
                break;
            default:
                printf(" \nInvaild choice!Please try again");
                break;
        }
    } while (opt != 4);
}