import java.util.Scanner;
class Matrix_Multiplication
{
  public static void main(String[] args)
  {
    Scanner scan = new Scanner(System.in);
    System.out.println("Enter the number of Rows of Matrix 1:");
    int row1= scan.nextInt();
    System.out.println("Enter the number of Columns of Matrix 1:");
    int col1=scan.nextInt();
    int mat1[][]=new int[row1][col1];
    System.out.println("Enter the Elements of Matrix 1:");
    for ( int i=0 ; i<row1 ; i++ )
      for ( int j=0 ; j<col1 ; j++ )
        mat1[i][j]=scan.nextInt();
    System.out.println("Enter the number of Rows of Matrix 2:");
    int row2= scan.nextInt();
    System.out.println("Enter the number of Columns of Matrix 2:");
    int col2=scan.nextInt();
    int mat2[][]=new int[row2][col2];
    System.out.println("Enter the Elements of Matrix 2:");
    for ( int i=0 ; i<row2 ; i++ )
      for ( int j=0 ; j<col2 ; j++ )
        mat2[i][j]=scan.nextInt();
    if (row2==col1)
    {
      int result[][]=new int[row1][col2];
      for ( int i=0 ; i<row1 ; i++ )
        for ( int j=0 ; j<col2 ; j++ )
          for (int k=0 ; k<row1 ; k++ )
            result[i][j]+=((mat1[i][k])*(mat2[k][j]));
      System.out.println("Result:");
      for ( int i=0 ; i<row1 ; i++ )
      {
        System.out.print("[\t");
        for ( int j=0 ; j<col2 ; j++ )
          System.out.print(result[i][j]+"\t");
        System.out.println("]");
      }
    }
    else
      System.out.println("Invalid Dimensions");
  }
}
