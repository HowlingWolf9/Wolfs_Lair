#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    int data
} *head = NULL, *temp, *newNode;

int createNode(int n)
{
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->data = n;

    if (head == NULL)
        head = newNode;
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void traverse()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d , ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete(int index)
{
    int i = 0;
    while (i != index)
        while (temp != NULL)
        {
            temp = temp->next;
            i++;
        }
    printf("%d %d", index, i);
}

void search(int key)
{
    int count = 0;
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
            printf("Element %d found at index %d \n", temp->data, count);
        count++;
        temp = temp->next;
    }
    char ans;
    printf("do you want to delete the element (Yes- y/No -n):");
    scanf(" %c", &ans);
    switch (ans)
    {
    case 'y':
        delete (count);
    case 'n':
        break;
    default:
        ("Invalid Input");
    }
}

int main()
{
    int opt;
    while (1)
    {
        printf("\nChoose option:\n");
        printf("1.create LL.\n2.display LL.\n3.Search.\n4.delete Node.\n5.Exit");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            int info;
            printf("Enter data for Linked list: \n");
            scanf("%d", &info);
            createNode(info);
            break;
        case 2:
            traverse(head);
            break;
        case 3:
            int key;
            printf("Enter element to search :\n");
            scanf("%d", &key);
            search(key);
            break;
        case 4:
            int index;
            printf("which node will you want to delete \n Enter index of node :\n");
            scanf("%d", &index);
            delete (index);
            break;
        case 5:
            exit(0);
        default:
            printf("invalid option selected");
            break;
        }
    }
}