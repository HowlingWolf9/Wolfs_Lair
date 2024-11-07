/*
AIM:  
Write program to perform Merge Sort on a set of Numbers. 

ALGORITHM:  
1. Function: mergeSort(arr[], left, right):
    1.1. Divide: 
        1.1.1. If left < right: 
            1.1.1.1. Calculate mid = left + (right - left) / 2. 
    1.2. Recursively Sort: 
        1.2.1. Call mergeSort(arr, left, mid) to sort the left half. 
        1.2.2. Call mergeSort(arr, mid + 1, right) to sort the right half. 
    1.3. Merge: 
        1.3.1. Call merge(arr, left, mid, right) to combine the sorted halves. 

2. Function: merge(arr[], left, mid, right):
    2.1. Initialize: 
        2.1.1. Define sizes n1 = mid - left + 1 and n2 = right - mid for two subarrays. 
    2.2. Copy Data: 
        2.2.1. Copy elements to temporary arrays L[n1] and R[n2]. 
    2.3. Merge Elements: 
        2.3.1. Use two pointers, i for L and j for R, to merge elements into arr. 
    2.4. Copy Remaining Elements: 
        2.4.1. Copy remaining elements from L and R to arr. 

3. Main Function:
    3.1. Input Array: 
        3.1.1. Read the number of elements n and populate arr. 
    3.2. Sort: 
        3.2.1. Call mergeSort(arr, 0, n - 1). 
    3.3. Output Sorted Array: 
        3.3.1. Display the sorted array using printArray. 
*/
//CODE: 
#include <stdio.h> 
 
void merge(int arr[], int left, int mid, int right) { 
    int i, j, k; 
    int n1 = mid - left + 1; // Size of left subarray 
    int n2 = right - mid;    // Size of right subarray 
 
    // Create temporary arrays 
    int L[n1], R[n2]; 
 
    // Copy data to temporary arrays L[] and R[] 
    for (i = 0; i < n1; i++) 
        L[i] = arr[left + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[mid + 1 + j]; 
 
    // Merge the temporary arrays back into arr[left..right] 
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = left; // Initial index of merged subarray 
 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
 
    // Copy the remaining elements of L[], if there are any 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
 
    // Copy the remaining elements of R[], if there are any 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
 
void mergeSort(int arr[], int left, int right) { 
    if (left < right) { 
        // Find the middle point 
        int mid = left + (right - left) / 2; 
 
        // Sort first and second halves 
        mergeSort(arr, left, mid); 
        mergeSort(arr, mid + 1, right); 
 
        // Merge the sorted halves 
        merge(arr, left, mid, right); 
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
 
    mergeSort(arr, 0, n - 1); 
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