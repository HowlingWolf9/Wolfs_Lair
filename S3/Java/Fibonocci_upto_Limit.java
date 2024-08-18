import java.util.Scanner;
class Fibonocci_upto_Limit
{
  public static void main(String[] args)
  {
    Scanner scan = new Scanner(System.in);
    System.out.println("Enter the Limit:");
    int lim= scan.nextInt();
    int first=0;
    int second=1;
    int fib=1;
    if ( lim<=0 )
      System.out.println("Enter a Number Greater than 0");
    else
    {
      System.out.print(first);
      while ( fib<lim )
      {
        System.out.print(","+fib);
        fib=second+first;
		    first=second;
		    second=fib;
      }
    }
  }
}
