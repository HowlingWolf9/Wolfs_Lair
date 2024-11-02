/*
AIM:
Write a menu driven program to perform the following operations on a Singly Linked List.
a. Insert at the beginning.
b. Insert at the end.
c. Insert in sorted order
d. Count the number of nodes.
e. Reverse the linked list.
f. Delete from beginning
g. Delete from end
h. Display the linked list.

ALGORITHM: main()
Step 01: START
Step 02: Initialize choice = 0
Step 03: WHILE (choice != 9) repeat steps 03 to 09
Step 04: 	Read the choice from the user, choice
Step 05:   	SWITCH to choice
Step 06:        CASE 1: Read the data from the user and call insertAtBeginning() function passing the address of head and data
Step 07:        CASE 2: Read the data from the user and Call insertAtEnd() function
Step 08:        CASE 3: Call insertInSortedOrder() function
Step 09:        CASE 4: Call countTheNumberOfNodes() function
Step 10: 		DEFAULT: Print "Invalid option"
Step 11: STOP

*/
// CODE:
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertInSortedOrder(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL || (*head)->data >= data)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL && temp->next->data < data)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void countTheNumberOfNodes(struct Node **head)
{
    struct Node *temp = *head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("The number of nodes is: %d\n", count);
}

void reverseTheLinkedList(struct Node **head)
{
    struct Node *current = *head;
    struct Node *prev = NULL;
    struct Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void deleteFromBeginning(struct Node **head)
{
    if (*head == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteFromEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    struct Node *temp = *head;
    struct Node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void displayTheLinkedList(struct Node **head)
{
    struct Node *temp = *head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    int data, choice = 0;
    struct Node *head = NULL;
    while (choice != 9)
    {
        printf("Menu\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert in sorted order\n");
        printf("4. Count the number of nodes\n");
        printf("5. Reverse the linked list\n");
        printf("6. Delete from beginning\n");
        printf("7. Delete from end\n");
        printf("8. Display the linked list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 3:
            printf("Enter the data: ");
            scanf("%d", &data);
            insertInSortedOrder(&head, data);
            break;
        case 4:
            countTheNumberOfNodes(&head);
            break;
        case 5:
            reverseTheLinkedList(&head);
            break;
        case 6:
            deleteFromBeginning(&head);
            break;
        case 7:
            deleteFromEnd(&head);
            break;
        case 8:
            displayTheLinkedList(&head);
            break;
        case 9:
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    printf("Exiting the program\n");
    system("cls");
}
