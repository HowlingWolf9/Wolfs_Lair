/*
Experiment: 2

AIM: Write a Java program to multiply two given matrices. 

ALGORITHM:
Read the number of rows and columns for the first matrix, rows1 and cols1
Read the number of columns for the second matrix, cols2
Declare the first matrix matrix1 of size rows1 x cols1, matrix1
Declare the second matrix matrix2 of size cols1 x cols2, matrix2
Declare the result matrix resultMatrix of size rows1 x cols2, resultMatrix
Read the values for the first matrix
Read the values for the second matrix
for (i = 0 to i < rows1)
{
    for (j = 0 to j < cols2)
    {
        set resultMatrix[i][j] = 0
        for (k = 0 to k < cols1)
        {
            set resultMatrix[i][j] = resultMatrix[i][j] + matrix1[i][k] * matrix2[k][j]
        }
        Increment k by 1
    }
    Increment j by 1
}
Increment i by 1
Display the resultant matrix, resultMatrix
*/
//CODE:
import java.util.Scanner;

public class MatrixMultiplication {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of rows for the first matrix: ");
        int rows1 = scanner.nextInt();

        System.out.print("Enter the number of columns for the first matrix (and rows for the second matrix): ");
        int cols1 = scanner.nextInt();

        System.out.print("Enter the number of columns for the second matrix: ");
        int cols2 = scanner.nextInt();

        int[][] matrix1 = new int[rows1][cols1];
        int[][] matrix2 = new int[cols1][cols2];
        int[][] resultMatrix = new int[rows1][cols2];

        System.out.println("Enter the values for the first matrix:");
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols1; j++) {
                matrix1[i][j] = scanner.nextInt();
            }
        }

        System.out.println("Enter the values for the second matrix:");
        for (int i = 0; i < cols1; i++) {
            for (int j = 0; j < cols2; j++) {
                matrix2[i][j] = scanner.nextInt();
            }
        }

        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols2; j++) {
                resultMatrix[i][j] = 0;
                for (int k = 0; k < cols1; k++) {
                    resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }

        System.out.println("The resultant matrix is:");
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols2; j++) {
                System.out.print(resultMatrix[i][j] + " ");
            }
            System.out.println();
        }
        
        scanner.close();
    }
}