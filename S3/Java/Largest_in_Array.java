import java.util.Scanner;
class Largest_in_Array
{
  public static void main(String[] args)
  {
    Scanner scan = new Scanner(System.in);
    System.out.println("Enter the size of the Array:");
    int size= scan.nextInt();
    int arr[]=new int[size];
    System.out.println("Enter the Elements in the Array:");
    for ( int i=0 ; i<size ; i++ )
        arr[i]=scan.nextInt();
    int largest=arr[0];
    for ( int i=0 ; i<size ; i++ )
        if ( largest<arr[i])
          largest=arr[i];
    System.out.println("Largest Element in the Array = "+largest);
  }
}
