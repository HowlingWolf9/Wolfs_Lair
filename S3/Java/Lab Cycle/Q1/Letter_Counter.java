import java.util.Scanner;

class Letter_Counter {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter the String:");
		String str = scan.nextLine();
		System.out.println("Enter the Letter:");
		char ch = scan.nextLine().charAt(0);
		int count = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) == ch) {
				count++;
			}
		}
		System.out.println("The Letter repeats " + count + " times");
		scan.close();
	}
}