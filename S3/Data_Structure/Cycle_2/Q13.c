/*
AIM:  
Discuss the implementation of polynomials using Linked lists. Write a program to read two polynomials in one variable and store it using linked lists, and perform addition and multiplication of the polynomials, display the resultant polynomials

ALGORITHM:  
1. Initialize the polynomial: 
    1.1. Define a structure Node with coeff (coefficient), exp (exponent), and next. 
    1.2. Initialize head as NULL.

2. Create polynomial: 
    2.1. For each term, create a new node. 
    2.2. Set newNode->coeff and newNode->exp to the term’s coefficient and exponent, respectively. 
    2.3. Insert newNode in the linked list in descending order of exp. 
    2.4. Repeat for all terms. 

3. Add two polynomials: 
    3.1. Initialize result as NULL. 
    3.2. Set p1 to the head of the first polynomial and p2 to the head of the second polynomial. 
    3.3. While both p1 and p2 are not NULL: 
        3.3.1. If p1->exp > p2->exp, copy p1's term to result, and move p1 to the next term. 
        3.3.2. If p1->exp < p2->exp, copy p2's term to result, and move p2 to the next term. 
        3.3.3. If p1->exp == p2->exp, add coefficients, copy the term to result, and move both p1 and p2 to the next term. 
    3.4. Append any remaining terms from p1 or p2 to result. 

4. Multiply two polynomials: 
    4.1. Initialize result as NULL. 
    4.2. For each term in the first polynomial, multiply it with every term in the second polynomial. 
    4.3. Insert the product terms into result, combining terms with the same exponent. 

5. Display polynomial: 
    5.1. Traverse the polynomial linked list. 
    5.2. Print each term in the format coeff x^exp. 
*/
//CODE: 
#include <stdio.h> 
#include <stdlib.h> 
 
struct Node { 
    int coeff; 
    int exp; 
    struct Node* next; 
}; 
 
void insertTerm(struct Node** poly, int coeff, int exp) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->coeff = coeff; 
    newNode->exp = exp; 
    newNode->next = NULL; 
 
    if (*poly == NULL || (*poly)->exp < exp) { 
        newNode->next = *poly; 
        *poly = newNode; 
    } else { 
        struct Node* temp = *poly; 
        while (temp->next != NULL && temp->next->exp > exp) 
            temp = temp->next; 
        newNode->next = temp->next; 
        temp->next = newNode; 
    } 
} 
 
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) { 
    struct Node* result = NULL; 
    while (poly1 != NULL && poly2 != NULL) { 
        if (poly1->exp > poly2->exp) { 
            insertTerm(&result, poly1->coeff, poly1->exp); 
            poly1 = poly1->next; 
        } else if (poly1->exp < poly2->exp) { 
            insertTerm(&result, poly2->coeff, poly2->exp); 
            poly2 = poly2->next; 
        } else { 
            int sum = poly1->coeff + poly2->coeff; 
            if (sum != 0) insertTerm(&result, sum, poly1->exp); 
            poly1 = poly1->next; 
            poly2 = poly2->next; 
        } 
    } 
    while (poly1 != NULL) { 
        insertTerm(&result, poly1->coeff, poly1->exp); 
        poly1 = poly1->next; 
    } 
    while (poly2 != NULL) { 
        insertTerm(&result, poly2->coeff, poly2->exp); 
        poly2 = poly2->next; 
    } 
    return result; 
} 
 
struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) { 
    struct Node* result = NULL; 
    for (struct Node* p1 = poly1; p1 != NULL; p1 = p1->next) { 
        for (struct Node* p2 = poly2; p2 != NULL; p2 = p2->next) { 
            int coeff = p1->coeff * p2->coeff; 
            int exp = p1->exp + p2->exp; 
            struct Node* temp = result; 
            while (temp != NULL && temp->exp != exp) temp = temp->next; 
            if (temp != NULL) { 
                temp->coeff += coeff; 
            } else { 
                insertTerm(&result, coeff, exp); 
            } 
        } 
    } 
    return result; 
} 
 
void displayPolynomial(struct Node* poly) { 
    while (poly != NULL) { 
        printf("%dx^%d", poly->coeff, poly->exp); 
        poly = poly->next; 
        if (poly != NULL) printf(" + "); 
    } 
    printf("\n"); 
} 
 
int main() { 
    struct Node* poly1 = NULL; 
    struct Node* poly2 = NULL; 
    struct Node* result = NULL; 
    int choice, coeff, exp, terms; 
 
    printf("Enter number of terms in the first polynomial: "); 
    scanf("%d", &terms); 
    for (int i = 0; i < terms; i++) { 
        printf("Enter coefficient and exponent: "); 
        scanf("%d %d", &coeff, &exp); 
        insertTerm(&poly1, coeff, exp); 
    } 
 
    printf("Enter number of terms in the second polynomial: "); 
    scanf("%d", &terms); 
    for (int i = 0; i < terms; i++) { 
        printf("Enter coefficient and exponent: "); 
        scanf("%d %d", &coeff, &exp); 
        insertTerm(&poly2, coeff, exp); 
    } 
 
    do { 
        printf("\nMenu:\n"); 
        printf("1. Add Polynomials\n"); 
        printf("2. Multiply Polynomials\n"); 
        printf("3. Display Polynomial 1\n"); 
        printf("4. Display Polynomial 2\n"); 
        printf("5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                result = addPolynomials(poly1, poly2); 
                printf("Result of addition: "); 
                displayPolynomial(result); 
                break; 
            case 2: 
                result = multiplyPolynomials(poly1, poly2); 
                printf("Result of multiplication: "); 
                displayPolynomial(result); 
                break; 
            case 3: 
                printf("Polynomial 1: "); 
                displayPolynomial(poly1); 
                break; 
            case 4: 
                printf("Polynomial 2: "); 
                displayPolynomial(poly2); 
                break; 
            case 5: 
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice! Try again.\n"); 
        } 
    } while (choice != 5); 
 
    return 0; 
}
/*
OUTPUT: 
Enter number of terms in the first polynomial: 2 
Enter coefficient and exponent: 3 2 
Enter coefficient and exponent: 5 1 
Enter number of terms in the second polynomial: 2 
Enter coefficient and exponent: 4 2 
Enter coefficient and exponent: 2 0 
Menu: 
1. Add Polynomials 
2. Multiply Polynomials 
3. Display Polynomial 1 
4. Display Polynomial 2 
5. Exit 
Enter your choice: 1 
Result of addition: 7x^2 + 5x^1 + 2x^0 
Menu: 
1. Add Polynomials 
2. Multiply Polynomials 
3. Display Polynomial 1 
4. Display Polynomial 2 
5. Exit 
Enter your choice: 2 
Result of multiplication: 12x^4 + 20x^3 + 6x^2 + 10x^1 
Menu: 
1. Add Polynomials 
2. Multiply Polynomials 
3. Display Polynomial 1 
4. Display Polynomial 2 
5. Exit 
Enter your choice: 5 
Exiting... 
*/