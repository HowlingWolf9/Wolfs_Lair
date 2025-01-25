// WAP to search for a data in a linked list . If found replace it with another. (Also display the list before and after searching)
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void insert(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void display()
{
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

void searchReplace()
{
    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == key)
        {
            printf("Element found.\nEnter the new element to Replace it with : ");
            scanf("%d", &key);
            temp->data = key;
            printf("New List: ");
            display();
            return;
        }
        temp = temp->next;
    }
    printf("Element does not exist in the list.");
}

void main()
{
    int opt, data;
    do
    {
        printf("\n1.Insert\t2.Search & Replace\t3.Exit\nEnter the Option: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter the element to add: ");
            scanf("%d", &data);
            insert(data);
            display();
            break;
        case 2:
            printf("Current List: ");
            display();
            searchReplace();
            break;
        case 3:
            break;
        default:
            printf("Invalid Option.\n");
        }
    } while (opt != 3);
    printf("Successfully Exited.");
}