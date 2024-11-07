/*
AIM:  
Implement Binary search as 
a. Iterative function 
b. Recursive function  

ALGORITHM:  
1. Function: binarySearchIterative(arr[], n, target):
    1.1. Initialize: 
        1.1.1. Set low = 0 and high = n - 1. 
    1.2. Loop until low exceeds high: 
        1.2.1. Calculate mid = low + (high - low) / 2. 
    1.3. Check Target: 
        1.3.1. If arr[mid] == target, return mid (target found). 
        1.3.2. If arr[mid] < target, set low = mid + 1 to search in the right half. 
        1.3.3. If arr[mid] > target, set high = mid - 1 to search in the left half. 
    1.4. Return: 
        1.4.1. If the target is not found, return -1. 

2. Function: binarySearchRecursive(arr[], low, high, target) 
    2.1. Base Case: 
        2.1.1. If low > high, return -1 (target not found). 
    2.2. Calculate Mid: 
        2.2.1. Set mid = low + (high - low) / 2. 
    2.3. Check Target: 
        2.3.1. If arr[mid] == target, return mid (target found). 
        2.3.2. If arr[mid] < target, call binarySearchRecursive(arr, mid + 1, high, target) to search in the right half. 
        2.3.3. If arr[mid] > target, call binarySearchRecursive(arr, low, mid - 1, target) to search in the left half.

3. Main Function:
    3.1. Input Array and Target: 
        3.1.1. Read n, populate arr with sorted elements, and read the target value. 
    3.2. Iterative Search: 
        3.2.1. Call binarySearchIterative(arr, n, target) and print result. 
    3.3. Recursive Search: 
        3.3.1. Call binarySearchRecursive(arr, 0, n - 1, target) and print result. 
*/
//CODE: 
#include <stdio.h> 
 
int binarySearchIterative(int arr[], int n, int target) { 
    int low = 0, high = n - 1; 
 
    while (low <= high) { 
        int mid = low + (high - low) / 2; 
 
        if (arr[mid] == target) 
            return mid; // Target found 
        else if (arr[mid] < target) 
            low = mid + 1; // Search in the right half 
        else 
            high = mid - 1; // Search in the left half 
    } 
    return -1; // Target not found 
} 
 
int binarySearchRecursive(int arr[], int low, int high, int target) { 
    if (low > high) 
        return -1; // Target not found 
 
    int mid = low + (high - low) / 2; 
 
    if (arr[mid] == target) 
        return mid; // Target found 
    else if (arr[mid] < target) 
        return binarySearchRecursive(arr, mid + 1, high, target); // Search in the right half 
    else 
        return binarySearchRecursive(arr, low, mid - 1, target); // Search in the left half 
} 
 
int main() { 
    int arr[100], n, target, result; 
 
    printf("Enter number of elements: "); 
    scanf("%d", &n); 
    printf("Enter the sorted elements:\n"); 
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]); 
 
    printf("Enter the target value to search: "); 
    scanf("%d", &target); 
 
    // Perform iterative binary search 
    result = binarySearchIterative(arr, n, target); 
    if (result != -1) 
        printf("Iterative: Target %d found at index %d\n", target, result); 
    else 
        printf("Iterative: Target %d not found in the array\n", target); 
 
    // Perform recursive binary search 
result = binarySearchRecursive(arr, 0, n - 1, target); 
if (result != -1) 
printf("Recursive: Target %d found at index %d\n", target, result); 
else 
printf("Recursive: Target %d not found in the array\n", target); 
return 0; 
}
/*
OUTPUT: 
Enter number of elements: 5 
Enter the sorted elements: 
1 2 5 5 9 
Enter the target value to search: 5 
Iterative: Target 5 found at index 2 
Recursive: Target 5 found at index 2 
*/