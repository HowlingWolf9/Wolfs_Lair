#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
}*head = NULL;

void INSERT(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = head;
    head = newNode;
}

void DELETE(int data)
{
    struct Node *prev = NULL;
    struct Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == data)
        {
            printf("Deleted %d from the list", data);
            prev->link = curr->link;
            free(curr);
            return;
        }
        prev = curr;

        curr = curr->link;
    }
}

void DISPLAY()
{
    struct Node *curr = head;
    while (curr->link != NULL)
    {
        printf("%d->", curr->data);
        curr = curr->link;
    }
    printf("%d", curr->data);
}

void main()
{
    int n, opt, data;
    do{
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nSelect the Option: ");
        scanf("%d", &opt);
        switch(opt){
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                INSERT(data);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                DELETE(data);
                break;
            case 3:
                DISPLAY();
                break;
            case 4:
                break;
            default:
                printf("Invalid Option");
                break;
        }
    }while((opt != 4));
    printf("Exited Program Successfully.");
}