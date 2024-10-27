/*
Experiment: 4

AIM: Implement a Menu driven program to perform the following operations on a Stack  Data  Structure using Arrays. 
a. Pushing elements to the stack. 
b. Popping Elements from the stack. 
c. Display the contents of the Stack. 

ALGORITHM: main()
Step 01: START
Step 02: WHILE TRUE repeat steps 03 to 09
Step 03: Read the option from the user, opt
Step 04:     SWITCH to opt
Step 05:        CASE 1: Call push() function
Step 06:        CASE 2: Call pop() function
Step 07:        CASE 3: Call display() function
Step 08:        CASE 4: Print "Program Exited Successfully" and STOP
Step 09: 		DEFAULT: Print "Invalid option"
Step 10: STOP

ALGORITHM: push()
Step 01: START
Step 02: IF top < SIZE
Step 03:     Read the number
Step 04:     Increment top by 1
Step 05: ELSE
Step 06:     Print "Limit Exceeded"
Step 07: ENDIF
Step 08: STOP

ALGORITHM: pop()
Step 01: START
Step 02: IF (top > 0)
Step 03:     Set stack[top] = '\0'
Step 04:     Decrement top by 1
Step 05: ELSE
Step 06:     Print "Stack is empty"
Step 07: ENDIF
Step 08: STOP

ALGORITHM: display()
Step 01: START
Step 02: IF (top > 0)
Step 03:     Initialize i = top - 1 and repeat steps 05 to 06 until i >= 0
Step 04:        Print stack[i]
Step 05:        Decrement i by 1
Step 06: ELSE
Step 07:     Print "Stack is empty"
Step 08: ENDIF
Step 09: STOP
*/
#include <stdio.h>
#define SIZE 5
int top=0;
int stack[SIZE];
void push()
{
	if (top<SIZE)
	{
		printf("Enter the number:");
		scanf("%d",&stack[top]);
		(top)++;
	}
	else
		printf("Limit Exceeded\n");
}
void pop()
{
	if ((top)>0)
	{
		stack[top]='\0';
		(top)--;
	}
	else
		printf("Stack is empty\n");
}
void display()
{

	if ((top)>0)
		for(int i=(top-1);i>=0;i--)
			printf("[\t%d\t]\n",stack[i]);
	else
		printf("Stack is empty\n");
}
int main()
{
	int opt;
	while (1)
	{
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nSelect the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Program Exited Successfully\n");
				return 0;
			default:
				printf("Invalid operation\n");
				break;
		}
	}
}
/*
OUTPUT:
1.PUSH
2.POP
3.DISPLAY
4.EXIT
Select the option:1
Enter the number:1

1.PUSH
2.POP
3.DISPLAY
4.EXIT
Select the option:1
Enter the number:2

1.PUSH
2.POP
3.DISPLAY
4.EXIT
Select the option:1
Enter the number:3

1.PUSH
2.POP
3.DISPLAY
4.EXIT
Select the option:1
Enter the number:4

1.PUSH
2.POP
3.DISPLAY
4.EXIT
Select the option:1
Enter the number:5

1.PUSH
2.POP
3.DISPLAY
4.EXIT
Select the option:1
Limit Exceeded

1.PUSH
2.POP
3.DISPLAY
4.EXIT
Select the option:2

1.PUSH
2.POP
3.DISPLAY
4.EXIT
Select the option:3
[       4       ]
[       3       ]
[       2       ]
[       1       ]

1.PUSH
2.POP
3.DISPLAY
4.EXIT
Select the option:2

1.PUSH
2.POP
3.DISPLAY
4.EXIT
Select the option:3
[       3       ]
[       2       ]
[       1       ]

1.PUSH
2.POP
3.DISPLAY
4.EXIT
Select the option:2

1.PUSH
2.POP
3.DISPLAY
4.EXIT
Select the option:3
[       2       ]
[       1       ]

1.PUSH
2.POP
3.DISPLAY
4.EXIT
Select the option:2

1.PUSH
2.POP
3.DISPLAY
4.EXIT
Select the option:2

1.PUSH
2.POP
3.DISPLAY
4.EXIT
Select the option:2
Stack is empty

1.PUSH
2.POP
3.DISPLAY
4.EXIT
Select the option:3
Stack is empty

1.PUSH
2.POP
3.DISPLAY
4.EXIT
Select the option:4
Program Exited Successfully
*/