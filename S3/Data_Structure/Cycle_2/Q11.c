/*
AIM:  
Implement a Stack Using Singly Linked List.

ALGORITHM:  
1. Initialize the stack: 
    1.1. Define a structure Node with data and next. 
    1.2. Initialize top as NULL. 

2. Push operation: 
    2.1. Create a new node. 
    2.2. Set newNode->data to the data value to be pushed. 
    2.3. Set newNode->next to top. 
    2.4. Update top to newNode. 

3. Pop operation: 
    3.1. If top is NULL, print "Stack Underflow" and return. 
    3.2. Set temp to top. 
    3.3. Update top to top->next. 
    3.4. Print temp->data as the popped element. 
    3.5. Free temp. 

4. Display the stack: 
    4.1. If top is NULL, print "Stack is empty". 
    4.2. Traverse the stack from top to NULL. 
    4.3. Print each node’s data.

*/
//CODE: 
#include <stdio.h> 
#include <stdlib.h> 
 
struct Node { 
    int data; 
    struct Node* next; 
}; 
 
void push(struct Node** top, int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    newNode->next = *top; 
    *top = newNode; 
    printf("Pushed %d onto the stack.\n", data); 
} 
 
void pop(struct Node** top) { 
    if (*top == NULL) { 
        printf("Stack Underflow\n"); 
        return; 
    } 
    struct Node* temp = *top; 
    printf("Popped %d from the stack.\n", temp->data); 
    *top = (*top)->next; 
    free(temp); 
} 
 
void displayStack(struct Node* top) { 
    if (top == NULL) { 
        printf("Stack is empty.\n"); 
        return; 
    } 
    struct Node* temp = top; 
    printf("Stack contents: "); 
    while (temp != NULL) { 
        printf("%d -> ", temp->data); 
        temp = temp->next; 
    } 
    printf("NULL\n"); 
} 
 
int main() { 
    struct Node* top = NULL; 
    int choice, data; 
 
    do { 
        printf("\nMenu:\n"); 
        printf("1. Push\n"); 
        printf("2. Pop\n"); 
        printf("3. Display stack\n"); 
        printf("4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter data to push onto the stack: "); 
                scanf("%d", &data); 
                push(&top, data); 
                break; 
            case 2: 
                pop(&top); 
                break; 
            case 3: 
                displayStack(top); 
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
1. Push 
2. Pop 
3. Display stack 
4. Exit 
Enter your choice: 1 
Enter data to push onto the stack: 10 
Pushed 10 onto the stack.

Menu: 
1. Push 
2. Pop 
3. Display stack 
4. Exit 
Enter your choice: 1 
Enter data to push onto the stack: 20 
Pushed 20 onto the stack. 

Menu: 
1. Push 
2. Pop 
3. Display stack 
4. Exit 
Enter your choice: 3 
Stack contents: 20 -> 10 -> NULL 

Menu: 
1. Push 
2. Pop 
3. Display stack 
4. Exit 
Enter your choice: 2 
Popped 20 from the stack. 

Menu: 
1. Push 
2. Pop 
3. Display stack 
4. Exit 
Enter your choice: 4 
Exiting... 
*/