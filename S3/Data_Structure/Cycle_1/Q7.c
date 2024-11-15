// CODE :
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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

int evaluatePostfix(char postfix[])
{
    int stack[100];
    int top = -1;
    int i = 0, op1, op2, result;
    while (postfix[i] != '\0')
    {
        if (isdigit(postfix[i]))
            stack[++top] = postfix[i] - '0';
        else if (is_operator(postfix[i]))
        {
            op2 = stack[top--];
            op1 = stack[top--];
            switch (postfix[i])
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                if (op2 == 0)
                {
                    printf("Division by zero error\n");
                    exit(1);
                }
                result = op1 / op2;
                break;
            case '^':
                result = 1;
                for (int j = 0; j < op2; j++)
                    result *= op1;
                break;
            default:
                printf("\nInvalid operator: %c\n", postfix[i]);
                exit(1);
            }
            stack[++top] = result;
        }
        else
        {
            printf("\nInvalid character in postfix expression.\n");
            exit(1);
        }
        i++;
    }
    return stack[top];
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
    int result;
    if (flag == 1)
    {
        result = evaluatePostfix(postfix);
        printf("Result of Postfix Evaluation: %d\n", result);
    }
    return 0;
}
/*
OUTPUT:

Enter size of stack: 10
Assume the infix expression contains single letter variables and single digit constants only.

Enter Infix expression: 1+9*7*8^2/5
Postfix Expression: 197*82^*5/+
Result of Postfix Evaluation: 807

Enter size of stack: 10
Assume the infix expression contains single letter variables and single digit constants only.

Enter Infix expression: a+b*c/d+e
Postfix Expression: abc*d/+e+

Enter size of stack: 10
Assume the infix expression contains single letter variables and single digit constants only.

Enter Infix expression: 1+3*7*9/6^2+9*4
Postfix Expression: 137*9*62^/+94*+
Result of Postfix Evaluation: 42

*/