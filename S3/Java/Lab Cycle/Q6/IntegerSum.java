import java.util.StringTokenizer;
import java.util.Scanner;

public class IntegerSum {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a line of integers: ");
        String input = scanner.nextLine();

        StringTokenizer tokenizer = new StringTokenizer(input);
        int sum = 0;

        System.out.println("Individual integers: ");
        while (tokenizer.hasMoreTokens()) {
            String token = tokenizer.nextToken();
            int integer = Integer.parseInt(token);
            System.out.println(integer);
            sum += integer;
        }

        System.out.println("Sum of all integers: " + sum);
        scanner.close();
    }
}