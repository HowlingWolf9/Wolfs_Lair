/*
Experiment: 1

AIM: Write a Java Program to find the frequency of a given character in a string.

ALGORITHM:
Read string, str
Read the character to find the frequency, c
Store the length of the string in n
Initialize count to 0

for (s = 0 to s < n)
{
    check if the character at index s in str is equal to c.
    if yes, increment count by 1

    Increment s by 1
}

Display count as the frequency of c
*/
//CODE:
import java.util.Scanner;

public class CharacterFrequency {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the string: ");
        String str = scanner.nextLine();

        System.out.print("Enter the character to find the frequency: ");
        char c = scanner.next().charAt(0);

        int n = str.length();
        int count = 0;

        for (int s = 0; s < n; s++)
            if (str.charAt(s) == c) {
                count++;
            }
            System.out.println("The frequency of character '" + c + "' in the string is: " + count);

            scanner.close();
    }
}
