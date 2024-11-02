/*
Experiment: 7

AIM: Write a Java program that implements a multi-threaded program which has three threads. First thread generates a random integer every 1 second. If the value is even, second thread computes the square of the number and prints. If the value is odd the third thread will print the value of cube of the number.

ALGORITHM:
Initialize num = 0, flag = 0

Create thread-1
for (i = 0 to i < 100)
{
    Create random number between 0 and 999 and store it in num
    Print num
    Set flag = 1
    Sleep for 1 second
    Increment i by 1
}

Create thread-2
for (i = 1 to i < 100)
{
    If (flag != 0)
    {
        Set n = num
        Set flag = 0
        If n is odd
        {
            Set res = cube of n
            Print n is odd. Cube is res
        }
        Sleep for 3 Seconds
    }
    Increment i by 1
}

Create thread-3
for (i = 1 to i < 100)
{
    If (flag != 0)
    {
        Set n = num
        Set flag = 0
        If n is even
        {
            Set res = square of n
            Print n is even. square is res
        }
        Sleep for 300 milliseconds
    }
    Increment i by 1
}

Start thread-1
Start thread-2
Start thread-3
Join thread-1
Join thread-2
Join thread-3
*/
//CODE:
import java.util.Random;

public class EvenOddSharedVarB {
    static int num = 0;
    static int flag = 0; // Set by thread-1 after placing data in num
    // Reset by thread-2 and thread-3 after checking data

    public static void main(String[] args) {
        Thread thread1 = new Thread(() -> {
            for (int i = 0; i < 100; i++) {
                Random rand = new Random();
                // create random number between 0 and 999
                num = rand.nextInt(1000);
                System.out.println("Generated " + i + "th number :" + num);
                flag = 1;
                try {
                    Thread.sleep(1000); // sleep 300 ms
                } catch (InterruptedException e) {
                }
            }
        });
        Thread thread2 = new Thread(() -> {
            for (int i = 1; i < 100; i++) {
                // System.out.println("Checking odd");
                if (flag != 0) {
                    int n = num;
                    flag = 0;
                    if (n % 2 != 0) {
                        double res;
                        res = Math.pow(n, 3);
                        System.out.println(n + " is Odd. Cube is " + res);
                    }
                }
                try {
                    Thread.sleep(3000); // sleep 3000 milli seconds
                } catch (InterruptedException e) {
                }
            }
        });
        Thread thread3 = new Thread(() -> {
            for (int i = 0; i < 100; i++) {
                // System.out.println("Checking Even");
                if (flag != 0) {
                    int n = num;
                    flag = 0;
                    if (n % 2 == 0) {
                        double res;
                        res = Math.pow(n, 2);
                        System.out.println(n + " is Even. Square is " + res);
                    }
                }
                try {
                    Thread.sleep(300); // sleep 300 milli seconds
                } catch (InterruptedException e) {
                }
            }
        });
        thread1.start();
        thread2.start();
        thread3.start();
        try {
            thread1.join();
            thread2.join();
            thread3.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}