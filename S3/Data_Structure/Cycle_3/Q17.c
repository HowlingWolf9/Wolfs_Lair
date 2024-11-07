/*
AIM:  
Write functions to perform the following Sorting on a Set of numbers.   
a. Selection Sort 
b. Bubble Sort 
c. Insertion Sort

ALGORITHM:  
1. Selection Sort: 
    1.1. Initialize the outer loop:  
        1.1.1. Start with i = 0. Repeat until i = n - 2 (where n is the size of the array). This loop defines the position to place the next minimum element. 
    1.2. Set the initial minimum index:  
        1.2.1. Set minIndex = i, assuming the element at index i is the smallest. 
    1.3. Inner loop to find the minimum element:  
        1.3.1. Initialize j = i + 1. Repeat until j = n - 1.  
        1.3.2. Compare arr[j] with arr[minIndex]: 
            1.3.2.1. If arr[j] < arr[minIndex], set minIndex = j.  
        1.3.3. End of the inner loop identifies the minimum element’s index.  
    1.4. Swap elements:  
        1.4.1. If minIndex is not equal to i, swap arr[i] with arr[minIndex]. 
    1.5. Increment i and repeat steps 2-4 until the entire array is sorted. 

2. Bubble Sort: 
    2.1. Initialize the outer loop: 
        2.1.1. Start with i = 0. Repeat until i = n - 2. Each iteration places the next largest element at the end of the unsorted portion. 
    2.2. Inner loop for comparisons and swaps:  
        2.2.1. Initialize j = 0. Repeat until j = n - i - 2.  
        2.2.2. Compare arr[j] and arr[j + 1]:  
            2.2.2.1. If arr[j] > arr[j + 1], swap arr[j] with arr[j + 1].  
        2.2.3. This inner loop "bubbles" the largest unsorted element to its correct position at the end. 
    2.3. Increment i and repeat steps 2-3 until the entire array is sorted. 

3. Insertion Sort: 
    3.1. Initialize the outer loop: 
        3.1.1. Start with i = 1. Repeat until i = n - 1. This loop identifies the current element (key) to insert into the sorted portion. 
    3.2. Store the key:  
        3.2.1. Set key = arr[i]. key is the element to be inserted into the sorted portion on the left. 
    3.3. Inner loop to shift elements: 
        3.3.1. Initialize j = i - 1. Repeat until j >= 0 and arr[j] > key.  
        3.3.2. If arr[j] > key, shift arr[j] one position to the right (arr[j + 1] = arr[j]).  
        3.3.3. Decrement j by 1 to continue shifting elements. 
    3.4. Insert the key:  
        3.4.1. Place key in the correct position (arr[j + 1] = key). 
    3.5. Increment i and repeat steps 2-4 until the entire array is sorted. 

4. Main Function:  
    4.1. Prompt the user to input the number of elements (n) and the array elements.  
    4.2. Menu for Sorting Choices: 
        4.2.1. Display a menu for the sorting options and read the user’s choice. 
    4.3. Based on the choice: 
        4.3.1. If the choice is 1, call selectionSort() and print the sorted array. 
        4.3.2. If the choice is 2, call bubbleSort() and print the sorted array.  
        4.3.3. If the choice is 3, call insertionSort() and print the sorted array. 
        4.3.4. If the choice is 4, exit the program. 4.4.  
    4.4. Loop back to the menu until the user selects Exit. 
*/
//CODE: 
#include <stdio.h> 
 
void selectionSort(int arr[], int n) { 
    for (int i = 0; i < n - 1; i++) { 
        int minIndex = i; 
        for (int j = i + 1; j < n; j++) 
            if (arr[j] < arr[minIndex]) 
                minIndex = j; 
        // Swap the found minimum element with the first element 
        int temp = arr[minIndex]; 
        arr[minIndex] = arr[i]; 
        arr[i] = temp; 
    } 
} 
 
void bubbleSort(int arr[], int n) { 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = 0; j < n - i - 1; j++) 
            if (arr[j] > arr[j + 1]) { 
                // Swap arr[j] and arr[j+1] 
                int temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
            } 
    } 
} 
 
void insertionSort(int arr[], int n) { 
    for (int i = 1; i < n; i++) { 
        int key = arr[i]; 
        int j = i - 1; 
        // Move elements of arr[0..i-1], that are greater than key, 
        // to one position ahead of their current position 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j--; 
        } 
        arr[j + 1] = key; 
    } 
} 
 
void printArray(int arr[], int size) { 
    for (int i = 0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
 
int main() { 
    int arr[100], n, choice; 
 
    printf("Enter number of elements: "); 
    scanf("%d", &n); 
    printf("Enter the elements:\n"); 
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]); 
 
    while (1) { 
        printf("\nMenu:\n1. Selection Sort\n2. Bubble Sort\n3. Insertion Sort\n4. Exit\nEnter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                selectionSort(arr, n); 
                printf("Sorted array (Selection Sort): "); 
                printArray(arr, n); 
                break; 
            case 2: 
                bubbleSort(arr, n); 
                printf("Sorted array (Bubble Sort): "); 
                printArray(arr, n); 
                break; 
            case 3: 
                insertionSort(arr, n); 
                printf("Sorted array (Insertion Sort): "); 
                printArray(arr, n); 
                break; 
            case 4: 
                printf("Exiting...\n"); 
                return 0; 
            default: 
                printf("Invalid choice. Please try again.\n"); 
        } 
    } 
}  
/*
OUTPUT: 
Enter number of elements: 5 
Enter the elements: 
5 2 9 1 5 

Menu: 
1. Selection Sort 
2. Bubble Sort 
3. Insertion Sort 
4. Exit 
Enter your choice: 1 
Sorted array (Selection Sort): 1 2 5 5 9  

Menu: 
1. Selection Sort 
2. Bubble Sort 
3. Insertion Sort 
4. Exit 
Enter your choice: 2 
Sorted array (Bubble Sort): 1 2 5 5 9

Menu: 
1. Selection Sort 
2. Bubble Sort 
3. Insertion Sort 
4. Exit 
Enter your choice: 3 
Sorted array (Insertion Sort): 1 2 5 5 9  

Menu: 
1. Selection Sort 
2. Bubble Sort 
3. Insertion Sort 
4. Exit 
Enter your choice: 4 
Exiting... 
*/