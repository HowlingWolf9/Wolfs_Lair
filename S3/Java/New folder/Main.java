import java.util.Scanner;

class Main {
    static void find(int arr[], int target) {
        int flag = 0;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++) {
                if (arr[i] + arr[j] == target && i != j) {
                    System.out.println("{" + arr[i] + ", " + arr[j] + "}");
                    flag = 1;
                }
            }
        if (flag == 0)
            System.out.println("No such pair exists");
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int arr[] = new int[10];
        int target;
        System.out.println("Enter array elements:");
        for (int i = 0; i < 10; i++) {
            arr[i] = scan.nextInt();
        }
        System.out.println("Enter target:");
        target = scan.nextInt();
        scan.close();
        find(arr, target);
    }
}