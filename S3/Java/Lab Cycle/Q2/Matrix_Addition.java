import java.util.Scanner;

class Matrix_Addition {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    System.out.println("Enter the number of Rows:");
    int row = scan.nextInt();
    System.out.println("Enter the number of Columns:");
    int col = scan.nextInt();
    int mat1[][] = new int[row][col];
    System.out.println("Enter the Elements of Matrix 1:");
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++)
        mat1[i][j] = scan.nextInt();
    int mat2[][] = new int[row][col];
    System.out.println("Enter the Elements of Matrix 2:");
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++)
        mat2[i][j] = scan.nextInt();
    int sum[][] = new int[row][col];
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++)
        sum[i][j] = mat1[i][j] + mat2[i][j];
    System.out.println("Result:");
    for (int i = 0; i < row; i++) {
      System.out.print("[\t");
      for (int j = 0; j < col; j++)
        System.out.print(sum[i][j] + "\t");
      System.out.println("]");
    }
    scan.close();
  }
}