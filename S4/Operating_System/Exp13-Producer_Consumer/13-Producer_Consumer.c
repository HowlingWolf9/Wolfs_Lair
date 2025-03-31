/*
ALGORITHM:
STEP 01: START
STEP 02: Include the necessary header files
STEP 03: Declare global variables mutex, x, full, empty
STEP 04: Define wait() and signal() functions
STEP 05: Define producer() function
STEP 06: Define consumer() function
STEP 07: Define main() function
STEP 08: Display choices to the user
STEP 09: Read the user's choice
STEP 10: Call the appropriate function based on the user's choice
STEP 11: STOP
*/
#include <stdio.h>

int mutex = 1, x = 0, full = 0, empty = 3;
int wait(int s) {
    return --s;
}

int signal(int s) {
    return ++s;
}

void producer() {
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("Producer produces the item %d.\n", x);
    mutex = signal(mutex);
}

void consumer() {
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("Consumer consumes the item %d.\n", x);
    x--;
    mutex = signal(mutex);
}

void main() {
    int ch;
    do {
        printf("==== YOUR CHOICES ====\n");
        printf("1. Producer\n");
        printf("2. Consumer\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                if ((mutex == 1) && (empty != 0))
                    producer();
                else 
                    printf("Buffer is full!\n");
                break;
            case 2:
                if ((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("Buffer is empty!\n");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (ch != 3);
}
/*
OUTPUT:
==== YOUR CHOICES ====
1. Producer
2. Consumer
3. Exit
Enter your choice: 1
Producer produces the item 1.
==== YOUR CHOICES ====
1. Producer
2. Consumer
3. Exit
Enter your choice: 2
Consumer consumes the item 1.
==== YOUR CHOICES ====
1. Producer
2. Consumer
3. Exit
Enter your choice: 0
Invalid choice! Try again.
==== YOUR CHOICES ====
1. Producer
2. Consumer
3. Exit
Enter your choice: 3
Exiting...
*/