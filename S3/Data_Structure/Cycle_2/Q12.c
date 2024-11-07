/*
AIM:  
Implement a Queue using a Circular Singly Linked List

ALGORITHM:  
1. Initialize the queue: 
    1.1. Define a structure Node with data and next. 
    1.2. Initialize rear as NULL. 

2. Enqueue operation (Insert at the end): 
    2.1. Create a new node. 
    2.2. Set newNode->data to the data value to be enqueued. 
    2.3. If rear is NULL, set newNode->next to itself and update rear to newNode. 
    2.4. Else, set newNode->next to rear->next and update rear->next to newNode. 
    2.5. Update rear to newNode. 

3. Dequeue operation (Delete from the beginning): 
    3.1. If rear is NULL, print "Queue Underflow" and return. 
    3.2. Set temp to rear->next. 
    3.3. If rear->next is rear, update rear to NULL. 
    3.4. Else, set rear->next to temp->next. 
    3.5. Print temp->data as the dequeued element. 
    3.6. Free temp. 

4. Display the queue: 
    4.1. If rear is NULL, print "Queue is empty". 
    4.2. Start from rear->next and traverse the queue until you reach rear again. 
    4.3. Print each node’s data. 
*/
//CODE: 
#include <stdio.h> 
#include <stdlib.h> 
 
struct Node { 
    int data; 
    struct Node* next; 
}; 
 
void enqueue(struct Node** rear, int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    if (*rear == NULL) { 
        newNode->next = newNode; 
        *rear = newNode; 
    } else { 
        newNode->next = (*rear)->next; 
        (*rear)->next = newNode; 
        *rear = newNode; 
    } 
    printf("Enqueued %d into the queue.\n", data); 
} 
 
void dequeue(struct Node** rear) { 
    if (*rear == NULL) { 
        printf("Queue Underflow\n"); 
        return; 
    } 
    struct Node* temp = (*rear)->next; 
    if (*rear == temp) { 
        *rear = NULL; 
    } else { 
        (*rear)->next = temp->next; 
    } 
    printf("Dequeued %d from the queue.\n", temp->data); 
    free(temp); 
} 
 
void displayQueue(struct Node* rear) { 
    if (rear == NULL) { 
        printf("Queue is empty.\n"); 
        return; 
    } 
    struct Node* temp = rear->next; 
    printf("Queue contents: "); 
    do { 
        printf("%d -> ", temp->data); 
        temp = temp->next; 
    } while (temp != rear->next); 
    printf("(rear)\n"); 
} 
 
int main() { 
    struct Node* rear = NULL; 
    int choice, data; 
 
    do { 
        printf("\nMenu:\n"); 
        printf("1. Enqueue\n"); 
        printf("2. Dequeue\n"); 
        printf("3. Display queue\n"); 
        printf("4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter data to enqueue: "); 
                scanf("%d", &data); 
                enqueue(&rear, data); 
                break; 
            case 2: 
                dequeue(&rear); 
                break; 
            case 3: 
                displayQueue(rear); 
                break; 
            case 4: 
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice! Try again.\n"); 
        } 
    } while (choice != 4); 
 
    return 0; 
}
/*
OUTPUT: 
Menu: 
1. Enqueue 
2. Dequeue 
3. Display queue 
4. Exit 
Enter your choice: 1 
Enter data to enqueue: 10 
Enqueued 10 into the queue. 

Menu: 
1. Enqueue 
2. Dequeue 
3. Display queue 
4. Exit 
Enter your choice: 1 
Enter data to enqueue: 20 
Enqueued 20 into the queue. 

Menu: 
1. Enqueue 
2. Dequeue 
3. Display queue 
4. Exit 
Enter your choice: 3 
Queue contents: 10 -> 20 -> (rear) 

Menu: 
1. Enqueue 
2. Dequeue 
3. Display queue 
4. Exit 
Enter your choice: 2 
Dequeued 10 from the queue. 

Menu: 
1. Enqueue 
2. Dequeue 
3. Display queue 
4. Exit 
Enter your choice: 4 
Exiting... 
*/