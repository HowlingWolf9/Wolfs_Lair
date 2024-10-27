/*
Experiment: 2

AIM: Implement Polynomial in one variable using Structure.Write function to perform addition of two polynomials in one variable.

ALGORITHM:
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
        printf("Enter the coefficent of the x^%d : ", i);
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