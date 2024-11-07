/*
AIM:  
Write a program to perform Quicksort on a set of numbers.

ALGORITHM:  
1. Function: quickSort(arr[], low, high):
    1.1. Base Condition: 
        1.1.1. If low < high, proceed; otherwise, exit. 
    1.2. Partitioning: 
        1.2.1. Find the partition index pi by calling partition(arr, low, high). 
    1.3. Recursive Calls: 
        1.3.1. Call quickSort(arr, low, pi - 1) to sort elements before the partition. 
        1.3.2. Call quickSort(arr, pi + 1, high) to sort elements after the partition. 

2. Function: partition(arr[], low, high):
    2.1. Initialize: 
        2.1.1. Set pivot as arr[high]. 
        2.1.2. Initialize i as low - 1 (to track the boundary of smaller elements). 
    2.2. Partitioning Process: 
        2.2.1. For each element arr[j] from low to high - 1: 
            2.2.1.1. If arr[j] <= pivot, increment i and swap arr[i] and arr[j] to place smaller elements on the left. 
    2.3. Final Swap: 
        2.3.1. Swap arr[i + 1] and arr[high] to place the pivot in its correct position. 
    2.4. Return: 
        2.4.1. Return i + 1 as the partition index. 

3. Main Function:
    3.1. Input Array: 
        3.1.1. Read the number of elements n and populate arr. 
    3.2. Sort Array: 
        3.2.1. Call quickSort(arr, 0, n - 1) to sort the array. 
    3.3. Display Sorted Array: 
        3.3.1. Print the sorted array using printArray. 
*/
//CODE: 
#include <stdio.h> 
 
void swap(int* a, int* b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
 
int partition(int arr[], int low, int high) { 
    int pivot = arr[high]; // Pivot element 
    int i = (low - 1); // Index of smaller element 
 
    for (int j = low; j < high; j++) { 
        // If current element is smaller than or equal to pivot 
        if (arr[j] <= pivot) { 
            i++; // Increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); // Return the partitioning index 
} 
 
void quickSort(int arr[], int low, int high) { 
    if (low < high) { 
        // Partitioning index 
        int pi = partition(arr, low, high); 
 
        // Recursively sort elements before and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
 
void printArray(int arr[], int size) { 
    for (int i = 0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
 
int main() { 
    int arr[100], n; 
 
    printf("Enter number of elements: "); 
    scanf("%d", &n); 
    printf("Enter the elements:\n"); 
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]); 
 
    quickSort(arr, 0, n - 1); 
    printf("Sorted array: "); 
    printArray(arr, n); 
    return 0; 
}
/*
OUTPUT: 
Enter number of elements: 5 
Enter the elements: 
5 2 9 1 5 
Sorted array: 1 2 5 5 9 
*/