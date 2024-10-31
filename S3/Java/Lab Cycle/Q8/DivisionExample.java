import java.util.Scanner;
import java.util.InputMismatchException;

public class DivisionExample {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.print("Enter an integer: ");
            int userInput = scanner.nextInt();
            // Attempt to divide 100 by the user input
            int result = 100 / userInput;
            System.out.println("Result: 100 / " + userInput + " = " + result);
        } catch (ArithmeticException e) {
            System.out.println("Error: Cannot divide by zero.");
        } catch (InputMismatchException e) {
            System.out.println("Error: Please enter a valid integer.");
        } finally {
            System.out.println("Execution completed.");
            scanner.close(); // Close the scanner to avoid resource leak
        }
    }
}