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