/*
Experiment: 6

AIM: Write a Java program that reads an integer input from the user. The program should attempt to divide 100 by this integer and display the result. However, if the user enters a zero, the program should catch the ArithmeticException and display an appropriate error message. Additionally, if the user inputs a non-integer value, catch the InputMismatchException and display an error message.Regardless of whether an exception is thrown or not, the program should always print a message in the finally block that says "Execution completed."

ALGORITHM:
In try block
{
    Read an integer input from the user, userInput
    Compute result = 100 / userInput
    Display result
}
Catch ArithmeticException
{
    Display "Error: Cannot divide by zero."
}
Catch InputMismatchException
{
    Display "Error: Please enter a valid integer."
}
Finally
{
    Display "Execution completed."
}
*/
//CODE:
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