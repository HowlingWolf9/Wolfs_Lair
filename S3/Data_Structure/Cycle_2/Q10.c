/*
AIM:  
Write a menu driven program to perform the following operations on a Circular 
Singly Linked list. 
a. Insert at the beginning. 
b. Insert at the end. 
c. Delete from Beginning. 
d. Delete from end 
e. Display the linked list.

ALGORITHM:  
1. Initialize the circular singly linked list: 
    1.1. Define a structure Node with data and next. 
    1.2. Initialize head as NULL.

2. Insert at the beginning: 
    2.1. Create a new node. 
    2.2. If head is NULL, set newNode->next to itself and head to newNode. 
    2.3. Else, set newNode->next to head. 
    2.4. Traverse to the last node, set lastNode->next to newNode. 
    2.5. Set head to newNode.

3. Insert at the end: 
    3.1. Create a new node. 
    3.2. If head is NULL, set newNode->next to itself and head to newNode.
    3.3. Else, traverse to the last node and set lastNode->next to newNode. 
    3.4. Set newNode->next to head.

4. Delete from beginning: 
    4.1. If head is NULL, return.
    4.2. If head->next is head, free head and set head to NULL. 
    4.3. Else, set temp to head. 
    4.4. Traverse to the last node, set lastNode->next to head->next. 
    4.5. Update head to head->next.
    4.6. Free temp. 

5. Delete from end: 
    5.1. If head is NULL, return. 
    5.2. If head->next is head, free head and set head to NULL. 
    5.3. Else, traverse to the second-last node.
    5.4. Update secondLastNode->next to head. 
    5.5. Free the last node.

6. Display the circular singly linked list: 
    6.1. Traverse the list starting from head. 
    6.2. Print each node’s data until reaching head again.

*/
//CODE: 
#include <stdio.h> 
#include <stdlib.h> 
 
struct Node { 
    int data; 
    struct Node* next; 
}; 
 
void insertBeginning(struct Node** head, int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    if (*head == NULL) { 
        newNode->next = newNode; 
        *head = newNode; 
        return; 
    } 
    struct Node* temp = *head; 
    while (temp->next != *head) temp = temp->next; 
    newNode->next = *head; 
    temp->next = newNode; 
    *head = newNode; 
} 
 
void insertEnd(struct Node** head, int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    if (*head == NULL) { 
        newNode->next = newNode; 
        *head = newNode; 
        return; 
    } 
    struct Node* temp = *head; 
    while (temp->next != *head) temp = temp->next; 
    temp->next = newNode; 
    newNode->next = *head; 
} 
 
void deleteBeginning(struct Node** head) { 
    if (*head == NULL) return; 
    if ((*head)->next == *head) { 
        free(*head); 
        *head = NULL; 
        return; 
    } 
    struct Node* temp = *head; 
    while (temp->next != *head) temp = temp->next; 
    struct Node* toDelete = *head; 
    temp->next = (*head)->next; 
    *head = (*head)->next; 
    free(toDelete); 
} 
 
void deleteEnd(struct Node** head) { 
    if (*head == NULL) return; 
    if ((*head)->next == *head) { 
        free(*head); 
        *head = NULL; 
        return; 
    } 
    struct Node* temp = *head; 
    while (temp->next->next != *head) temp = temp->next; 
    struct Node* toDelete = temp->next; 
    temp->next = *head; 
    free(toDelete); 
} 
 
void displayList(struct Node* head) { 
    if (head == NULL) { 
        printf("List is empty.\n"); 
        return; 
    } 
    struct Node* temp = head; 
    do { 
        printf("%d -> ", temp->data); 
        temp = temp->next; 
    } while (temp != head); 
    printf("(head)\n"); 
} 
 
int main() { 
    struct Node* head = NULL; 
    int choice, data; 
 
    do { 
        printf("\nMenu:\n"); 
        printf("1. Insert at the beginning\n"); 
        printf("2. Insert at the end\n"); 
        printf("3. Delete from beginning\n"); 
        printf("4. Delete from end\n"); 
        printf("5. Display the linked list\n"); 
        printf("6. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter data to insert at the beginning: "); 
                scanf("%d", &data); 
                insertBeginning(&head, data); 
                break; 
            case 2: 
                printf("Enter data to insert at the end: "); 
                scanf("%d", &data); 
                insertEnd(&head, data); 
                break; 
            case 3: 
                deleteBeginning(&head); 
                printf("Deleted from beginning.\n"); 
                break; 
            case 4: 
                deleteEnd(&head); 
                printf("Deleted from end.\n"); 
                break; 
            case 5: 
                printf("Circular linked list: "); 
                displayList(head); 
                break; 
            case 6: 
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice! Try again.\n"); 
        } 
    } while (choice != 6); 
 
    return 0; 
} 
/*
OUTPUT: 
Menu: 
1. Insert at the beginning 
2. Insert at the end 
3. Delete from beginning 
4. Delete from end 
5. Display the linked list 
6. Exit 
Enter your choice: 1 
Enter data to insert at the beginning: 10 
Menu: 
1. Insert at the beginning 
2. Insert at the end 
3. Delete from beginning 
4. Delete from end 
5. Display the linked list 
6. Exit 
Enter your choice: 2 
Enter data to insert at the end: 20 
Menu: 
1. Insert at the beginning 
2. Insert at the end 
3. Delete from beginning 
4. Delete from end 
5. Display the linked list 
6. Exit 
Enter your choice: 5 
Circular linked list: 10 -> 20 -> (head) 
Menu: 
1. Insert at the beginning 
2. Insert at the end 
3. Delete from beginning 
4. Delete from end 
5. Display the linked list 
6. Exit 
Enter your choice: 6 
Exiting... 
*/