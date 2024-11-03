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

ALGORITHM:
Step 01: START
Step 02: Initialize a structure of type Node with integer variable data and pointer variable next which points to the next node
Step 03: execute main() function
Step 04: STOP

ALGORITHM: main()
Step 01: START
Step 02: Initialize choice = 0
Step 03: WHILE (choice != 9) repeat steps 04 to 15
Step 04: 	Read the choice from the user, choice
Step 05:   	SWITCH to choice
Step 06:        CASE 1: Read the data from the user and call insertAtBeginning() function passing the address of head and data
Step 07:        CASE 2: Read the data from the user and call insertAtEnd() function passing the address of head and data
Step 08:        CASE 3: Read the data from the user and call insertInSortedOrder() function passing the address of head and data
Step 09:        CASE 4: Read the data from the user and call countTheNumberOfNodes() function passing the address of head
Step 10:        CASE 5: Call reverseTheLinkedList() function passing the address of head
Step 11:        CASE 6: Call deleteFromBeginning() function passing the address of head
Step 12:        CASE 7: Call deleteFromEnd() function passing the address of head
Step 13:        CASE 8: Call displayTheLinkedList() function passing the address of head
Step 14:        CASE 9: EXIT
Step 15: 		DEFAULT: Print "Invalid option"
Step 16: STOP

ALGORITHM: struct Node *createNode(int data)
Step 01: START
Step 02: Initialize newNode of type Node and allocate memory for it
Step 03: Set newNode->data = data
Step 04: Set newNode->next = NULL
Step 05: Return newNode
Step 06: STOP

ALGORITHM: insertAtBeginning(struct Node **head, int data)
Step 01: START
Step 02: Call createNode() function and pass the data as an argument
Step 03: Set newNode->next = *head
Step 04: Set *head = newNode
Step 05: STOP

ALGORITHM: insertAtEnd(struct Node **head, int data)
Step 01: START
Step 02: Call createNode() function and pass the data as an argument
Step 03: IF (*head == NULL)
Step 04:    Set *head = newNode
Step 05:    STOP
Step 06: ENDIF
Step 07: Initialize struct Node *temp = *head
Step 08: WHILE (temp->next != NULL) repeat step 08
Step 09:     Set temp = temp->next
Step 10: Set temp->next = newNode
Step 11: STOP

ALGORITHM: insertInSortedOrder(struct Node **head, int data)
Step 01: START
Step 02: Call createNode() function and pass the data as an argument
Step 03: IF (*head == NULL || (*head)->data >= data)
Step 04:    Set newNode->next = *head
Step 05:    Set *head = newNode
Step 06:    STOP
Step 07: ENDIF
Step 08: Initialize struct Node *temp = *head
Step 09: WHILE (temp->next != NULL && temp->next->data < data) repeat step 10
Step 10:     Set temp = temp->next
Step 11: Set newNode->next = temp->next
Step 12: Set temp->next = newNode
Step 13: STOP

ALGORITHM: countTheNumberOfNodes(struct Node **head)
Step 01: START
Step 02: Initialize struct Node *temp = *head
Step 03: Initialize count = 0
Step 04: WHILE (temp != NULL) repeat step 05 to 06
Step 05:     Increment count
Step 06:     Set temp = temp->next
Step 07: Print "The number of nodes is: " count
Step 08: STOP

ALGORITHM: reverseTheLinkedList(struct Node **head)
Step 01: START
Step 02: Initialize struct Node *current = *head
Step 03: Initialize struct Node *next = NULL
Step 04: Initialize struct Node *prev = NULL
Step 05: WHILE (current != NULL) repeat steps 06 to 09
Step 06:    Set next = current->next
Step 07:    Set current->next = prev
Step 08:    Set prev = current
Step 09:    Set current = next
Step 10: Set *head = prev
Step 11: STOP

ALGORITHM: deleteFromBeginning(struct Node **head)
Step 01: START
Step 02: IF (*head == NULL)
Step 03:    Print "The list is empty"
Step 04:    STOP
Step 05: ENDIF
Step 06: Initialize struct Node *temp = *head
Step 07: Set *head = temp->next
Step 08: Free memory of temp using free() function
Step 09: STOP

ALGORITHM: deleteFromEnd(struct Node **head)
Step 01: START
Step 02: IF (*head == NULL)
Step 03:    Print "The list is empty"
Step 04:    STOP
Step 05: ENDIF
Step 06: Initialize struct Node *temp = *head
Step 07: Initialize struct Node *prev = NULL
Step 08: WHILE (temp->next != NULL) repeat step 09
Step 09:     Set prev = temp
Step 10:     Set temp = temp->next
Step 11: Set prev->next = NULL
Step 12: Free memory of temp using free() function
Step 13: STOP

ALGORITHM: displayTheLinkedList(struct Node **head)
Step 01: START
Step 02: Initialize struct Node *temp = *head
Step 03: WHILE (temp != NULL) repeat step 04 to 05
Step 04:     Print temp->data " "
Step 05:     Set temp = temp->next
Step 06: STOP

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
        printf("\nMenu\n");
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
}

/*
OUTPUT:

Menu
1. Insert at the beginning
2. Insert at the end
3. Insert in sorted order
4. Count the number of nodes
5. Reverse the linked list
6. Delete from beginning
7. Delete from end
8. Display the linked list
9. Exit
Enter your choice: 1
Enter the data: 15

Menu
1. Insert at the beginning
2. Insert at the end
3. Insert in sorted order
4. Count the number of nodes
5. Reverse the linked list
6. Delete from beginning
7. Delete from end
8. Display the linked list
9. Exit
Enter your choice: 2
Enter the data: 10

Menu
1. Insert at the beginning
2. Insert at the end
3. Insert in sorted order
4. Count the number of nodes
5. Reverse the linked list
6. Delete from beginning
7. Delete from end
8. Display the linked list
9. Exit
Enter your choice: 3
Enter the data: 13

Menu
1. Insert at the beginning
2. Insert at the end
3. Insert in sorted order
4. Count the number of nodes
5. Reverse the linked list
6. Delete from beginning
7. Delete from end
8. Display the linked list
9. Exit
Enter your choice: 8                          
13 15 10

Menu
1. Insert at the beginning
2. Insert at the end
3. Insert in sorted order
4. Count the number of nodes
5. Reverse the linked list
6. Delete from beginning
7. Delete from end
8. Display the linked list
9. Exit
Enter your choice: 5

Menu
1. Insert at the beginning
2. Insert at the end
3. Insert in sorted order
4. Count the number of nodes
5. Reverse the linked list
6. Delete from beginning
7. Delete from end
8. Display the linked list
9. Exit
Enter your choice: 7

Menu
1. Insert at the beginning
2. Insert at the end
3. Insert in sorted order
4. Count the number of nodes
5. Reverse the linked list
6. Delete from beginning
7. Delete from end
8. Display the linked list
9. Exit
Enter your choice: 8
10 15

Menu
1. Insert at the beginning
2. Insert at the end
3. Insert in sorted order
4. Count the number of nodes
5. Reverse the linked list
6. Delete from beginning
7. Delete from end
8. Display the linked list
9. Exit
Enter your choice: 6

Menu
1. Insert at the beginning
2. Insert at the end
3. Insert in sorted order
4. Count the number of nodes
5. Reverse the linked list
6. Delete from beginning
7. Delete from end
8. Display the linked list
9. Exit
Enter your choice: 8
15

Menu
1. Insert at the beginning
2. Insert at the end
3. Insert in sorted order
4. Count the number of nodes
5. Reverse the linked list
6. Delete from beginning
7. Delete from end
8. Display the linked list
9. Exit
Enter your choice: 10

Invalid choice

Menu
1. Insert at the beginning
2. Insert at the end
3. Insert in sorted order
4. Count the number of nodes
5. Reverse the linked list
6. Delete from beginning
7. Delete from end
8. Display the linked list
9. Exit
Enter your choice:
9
Exiting the program
*/