/*
Experiment: 2

AIM: Implement Polynomial in one variable using Structure.Write function to perform addition of two polynomials in one variable.

ALGORITHM: main()
Step 01: Read the highest degree of the first polynomial
Step 02: Call readPoly() function and pass the address of p1
Step 03: Display the first polynomial using displayPoly() function and pass p1
Step 04: Read the highest degree of the second polynomial
Step 05: Call readPoly() function and pass the address of p2
Step 06: Display the second polynomial using displayPoly() function and pass p2
Step 07: IF p1.exp > p2.exp
Step 08:    Initialize i = 0 and repeat steps 09 to 11 until i <= p1.exp
Step 09:        Set p3.coeff[i] = p1.coeff[i] + p2.coeff[i]
Step 10:        Set p3.exp = p1.exp
Step 11:        Increment i by 1
Step 12: ELSE
Step 13:    Initialize i = 0 and repeat steps 14 to 16 until i <= p2.exp
Step 14:        Set p3.coeff[i] = p1.coeff[i] + p2.coeff[i]
Step 15:        Set p3.exp = p2.exp
Step 16:        Increment i by 1
Step 17: ENDIF
Step 18: Display the resultant polynomial using displayPoly() function and pass p3
Step 19: STOP

ALGORITHM: readPoly(struct poly *p)
Step 01: START
Step 02: Initialize i = p->exp and repeat steps 03 to 05 until i >= 0
Step 03:     Read the coefficent of the x^i
Step 04:     Decrement i by 1
Step 05: STOP

ALGORITHM: displayPoly(struct poly p)
Step 01: START
Step 02: Initialize i = p.exp and repeat steps 03 to 08 until i >= 0
Step 03:     IF i == 0
Step 04:         Print p.coeff[i]
Step 05:     ELSE
Step 06:         Print p.coeff[i] "x^" i " + "
Step 07:     ENDIF
Step 08:     Decrement i by 1
Step 09: STOP
*/
// CODE:
#include <stdio.h>

struct poly
{
    int coeff[10];
    int exp;
} p1, p2, p3;

void readPoly(struct poly *p)
{
    for (int i = p->exp; i >= 0; i--)
    {
        printf("Enter the coefficient of the x^%d: ", i);
        scanf("%d", &p->coeff[i]);
    }
}

void displayPoly(struct poly p)
{
    for (int i = p.exp; i >= 0; i--)
    {
        if (i == 0)
            printf("%d\n", p.coeff[i]);
        else
            printf("%dx^%d + ", p.coeff[i], i);
    }
}

void main()
{
    printf("Enter the highest degree of the first polynomial: ");
    scanf("%d", &p1.exp);
    readPoly(&p1);
    printf("\nFirst polynomial: ");
    displayPoly(p1);

    printf("\nEnter the highest degree of the second polynomial: ");
    scanf("%d", &p2.exp);
    readPoly(&p2);
    printf("\nSecond polynomial: ");
    displayPoly(p2);

    if (p1.exp > p2.exp)
    {
        for (int i = 0; i <= p1.exp; i++)
            p3.coeff[i] = p1.coeff[i] + p2.coeff[i];
        p3.exp = p1.exp;
    }
    else
    {
        for (int i = 0; i <= p2.exp; i++)
            p3.coeff[i] = p1.coeff[i] + p2.coeff[i];
        p3.exp = p2.exp;
    }
    printf("\nSum of polynomials: ");
    displayPoly(p3);
}

/*
OUTPUT:
Enter the highest degree of the first polynomial: 3
Enter the coefficient of the x^3: 2
Enter the coefficient of the x^2: 3
Enter the coefficient of the x^1: 1
Enter the coefficient of the x^0: 4

First polynomial: 2x^3 + 3x^2 + 1x^1 + 4

Enter the highest degree of the second polynomial: 2
Enter the coefficient of the x^2: 1
Enter the coefficient of the x^1: 2
Enter the coefficient of the x^0: 3

Second polynomial: 1x^2 + 2x^1 + 3

Sum of polynomials: 2x^3 + 5x^2 + 3x^1 + 7
*/