/*
AIM:
Write a menu driven program to perform the following operations on a Singly 
Linked List. 
a. Insert at the beginning. 
b. Insert at the end. 
c. Insert in sorted order 
d. Count the number of nodes. 
e. Reverse the linked list. 
f. Delete from beginning 
g. Delete from end 
h. Display the linked list. 
*/

#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

{

}
void insertAtBeginning();
{

}
void main()
{
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

    int choice;
    scanf("%d", &choice);

    struct node *head = NULL;

    switch (choice)
    {
    case 1:
        insertAtBeginning();
        break;
    case 2:
        insertAtEnd();
        break;
    case 3:
        insertInSortedOrder();
        break;
    case 4:
        countTheNumberOfNodes();
        break;
    case 5:
        reverseTheLinkedList();
        break;
    case 6:
        deleteFromBeginning();
        break;
    case 7:
        deleteFromEnd();
        break;
    case 8:
        displayTheLinkedList();
        break;  
    case 9:
        printf("Exiting the program\n");
        return 0;
    default:
        printf("Invalid choice\n");
    }
}
