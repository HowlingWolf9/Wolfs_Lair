import java.util.Scanner;
class Sum_of_Diagonals
{
  public static void main(String[] args)
  {
    Scanner scan = new Scanner(System.in);
    System.out.println("Enter the size of the Matrix:");
    int dim= scan.nextInt();
    int mat[][]=new int[dim][dim];
    System.out.println("Enter the Elements of Matrix:");
    for ( int i=0 ; i<dim ; i++ )
      for ( int j=0 ; j<dim ; j++ )
        mat[i][j]=scan.nextInt();
    int sum=0;
    for ( int i=0 ; i<dim ; i++ )
        sum+=mat[i][i];
    System.out.println("Sum="+sum);
    }
}
