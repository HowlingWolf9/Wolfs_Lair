import java.util.Scanner;
class add_user
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter the 1st Number:");
		int a=scan.nextInt();
		System.out.println("Enter the 2nd Number:");
		int b=scan.nextInt();
		int c=a+b;
		System.out.println("c="+c);
	}
}