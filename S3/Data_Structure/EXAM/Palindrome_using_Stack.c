#include <stdio.h>
#define SIZE 30
char stack[SIZE];
int top = -1;

void PUSH(char ch)
{
    stack[++top] = ch;
}

void POP()
{
    top--;
}

int checkPalindrome(char str[])
{
    int i;
    for(i = 0; str[i] != '\0'; i++)
        PUSH(str[i]);
    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != stack[top])
            return 0;
        POP();
    }
    return 1;
}

void main()
{
    char str[SIZE];
    printf("Enter a string: ");
    scanf("%s", str);
    if(checkPalindrome(str))
        printf("%s is a palindrome", str);
    else
        printf("%s is not a palindrome", str);
}