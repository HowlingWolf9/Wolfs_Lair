#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char stack[100];
int top = -1, size;
int flag = 0;

void push(char item)
{
    if (top >= size - 1)
    {
        printf("\nStack Overflow.");
        exit(1);
    }
    else
        stack[++top] = item;
}

char pop()
{
    if (top < 0)
    {
        printf("\nStack Underflow\n");
        exit(1);
    }
    else
        return stack[top--];
}

int is_operator(char symbol)
{
    return (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-');
}

int precedence(char symbol)
{
    if (symbol == '^')
        return 3;
    else if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}

void InfixToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char item;
    push('(');
    strcat(infix, ")");
    item = infix[i];
    while (item != '\0')
    {
        if (item == '(')
            push(item);
        else if (isdigit(item))
        {
            flag = 1;
            postfix[j++] = item;
        }
        else if (isalpha(item))
            postfix[j++] = item;
        else if (is_operator(item))
        {
            while (top != -1 && is_operator(stack[top]) && precedence(stack[top]) >= precedence(item))
                postfix[j++] = pop();
            push(item);
        }
        else if (item == ')')
        {
            while (top != -1 && (stack[top] != '('))
                postfix[j++] = pop();
            pop();
        }
        else
        {
            printf("\nInvalid infix Expression.\n");
            exit(1);
        }
        i++;
        item = infix[i];
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[100], postfix[100];
    printf("\nEnter size of stack: ");
    scanf("%d", &size);
    printf("Assume the infix expression contains single letter variables and single digit constants only.\n");
    printf("\nEnter Infix expression: ");
    scanf(" %s", infix);
    InfixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}
