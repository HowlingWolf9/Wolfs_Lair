/*
AIM:  
Write a program to create a Binary Tree and perform the following traversals on it.  
1. Inorder  
2. Preorder  
3. Postorder

ALGORITHM:  
1. Initialize the Binary Tree: 
    1.1. Define a structure Node with data, left, and right. 
    1.2. Initialize the root as NULL. 

2. Insert: 
    2.1. Create a new node with user input. 
    2.2. Attach the node to the tree based on user input (for simplicity, this example will not implement specific insertion logic, so you can input data sequentially).

3. Inorder Traversal: 
    3.1. Traverse the left subtree, visit the root node, and then traverse the right subtree. 

4. Preorder Traversal: 
    4.1. Visit the root node, traverse the left subtree, and then traverse the right subtree. 

5. Postorder Traversal: 
    .5.1. Traverse the left subtree, traverse the right subtree, and then visit the root node. 
*/
//CODE: 
#include <stdio.h> 
#include <stdlib.h> 
 
struct Node { 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 
 
struct Node* createNode(int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
} 
 
void inorder(struct Node* root) { 
    if (root != NULL) { 
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); 
    } 
} 
 
void preorder(struct Node* root) { 
    if (root != NULL) { 
        printf("%d ", root->data); 
        preorder(root->left); 
        preorder(root->right); 
    } 
} 
 
void postorder(struct Node* root) { 
    if (root != NULL) { 
        postorder(root->left); 
        postorder(root->right); 
        printf("%d ", root->data); 
    } 
} 
 
int main() { 
    struct Node* root = NULL; 
    int data, choice, n; 
 
    printf("Enter the number of nodes in the binary tree: "); 
    scanf("%d", &n); 
     
    for (int i = 0; i < n; i++) { 
        printf("Enter data for node %d: ", i + 1); 
        scanf("%d", &data); 
        if (root == NULL) { 
            root = createNode(data); // Initialize the root with the first input 
        } else { 
            // Simple insertion logic: left for smaller, right for larger (not a balanced BST) 
            struct Node* current = root; 
            struct Node* parent = NULL; 
            while (1) { 
                parent = current; 
                if (data < current->data) { 
                    current = current->left; 
                    if (current == NULL) { 
                        parent->left = createNode(data); 
                        break; 
                    } 
                } else { 
                    current = current->right; 
                    if (current == NULL) { 
                        parent->right = createNode(data); 
                        break; 
                    } 
                } 
            } 
        } 
    } 
 
    while (1) { 
        printf("\nMenu:\n1. Inorder Traversal\n2. Preorder Traversal\n3. Postorder Traversal\n4. Exit\nEnter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Inorder Traversal: "); 
                inorder(root); 
                printf("\n"); 
                break; 
            case 2: 
                printf("Preorder Traversal: "); 
                preorder(root); 
                printf("\n"); 
                break; 
            case 3: 
                printf("Postorder Traversal: "); 
                postorder(root); 
                printf("\n"); 
                break; 
            case 4: 
                printf("Exiting...\n"); 
                exit(0); 
            default: 
                printf("Invalid choice. Please try again.\n"); 
        } 
    } 
    return 0; 
}
/*
OUTPUT: 
Enter the number of nodes in the binary tree: 5 
Enter data for node 1: 10 
Enter data for node 2: 5 
Enter data for node 3: 15 
Enter data for node 4: 3 
Enter data for node 5: 7

Menu: 
1. Inorder Traversal 
2. Preorder Traversal 
3. Postorder Traversal 
4. Exit 
Enter your choice: 1 
Inorder Traversal: 3 5 7 10 15 

Menu: 
1. Inorder Traversal 
2. Preorder Traversal 
3. Postorder Traversal 
4. Exit 
Enter your choice: 2 
Preorder Traversal: 10 5 3 7 15 

Menu: 
1. Inorder Traversal 
2. Preorder Traversal 
3. Postorder Traversal 
4. Exit 
Enter your choice: 3 
Postorder Traversal: 3 7 5 15 10  

Menu: 
1. Inorder Traversal 
2. Preorder Traversal 
3. Postorder Traversal 
4. Exit 
Enter your choice: 4 
Exiting... 
*/