/*
Experiment: 4

AIM: Write a Java program that reads a line of integers, and then displays each integer, and the sum of all the integers (Use String Tokenizer class of java.util).

ALGORITHM:
Read lines from data file, data.txt to string variable s until there are no lines in file to be read
{
    Create a stringTokenizer object to store tokens after splitting the line read based on delimiter, ","
    Display the tokens
    Sum up the tokens after Converting them to integers
    Display the sum
}
*/
//CODE:
import java.io.*;
import java.util.*;

class FindSum {
    Scanner sc;
    String path = "data.txt";

    void calculate() {
        try {
            InputStream is = new FileInputStream(path);
            Scanner sc = new Scanner(is);
            // It holds true till there is single element left in the object with usage of hasNext() method
            String s;
            int sum = 0;
            while (sc.hasNextLine()) {
                s = sc.nextLine();
                System.out.println(s);
                sum = 0;
                // tokenize the line read from data.txt
                StringTokenizer st1 = new StringTokenizer(s, ",");
                while (st1.hasMoreTokens()) {
                    // Getting next tokens
                    int num = Integer.parseInt(st1.nextToken());
                    sum = sum + num;
                }
                System.out.println(sum);
            }
        } catch (IOException e) {
        }
    }// end calculate
}

public class NumSumA {
    public static void main(String s[]) {
        FindSum x = new FindSum();
        x.calculate();
    }
}