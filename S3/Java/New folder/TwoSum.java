import java.util.Scanner;

class Solution {
    public int[] sum(int arr[], int tar) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) { // Start j from i + 1 to avoid using the same element
                if (arr[i] + arr[j] == tar) {
                    return new int[]{arr[i], arr[j]}; // Return the elements in an array
                }
            }
        }
        return new int[]{}; // Return an empty array if no solution is found
    }
}

class TwoSum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements for your array:");
        int size = sc.nextInt(); // Fixed the method for reading size
        int[] arr = new int[size]; // Added the type declaration for arr
        System.out.println("Enter the values of your array:");
        for (int i = 0; i < size; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println("Enter the Target number:");
        int tar = sc.nextInt(); // Fixed the method for reading the target
        Solution x = new Solution();
        int[] result = x.sum(arr, tar); // Corrected method call

        if (result.length == 0) {
            System.out.println("No two numbers found that add up to the target.");
        } else {
            System.out.println("The two numbers are: " + result[0] + " and " + result[1]);
        }
    }
}