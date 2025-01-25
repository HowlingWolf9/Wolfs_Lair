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

class NumberGenerator extends Thread {
    private SharedData sharedData;

    public NumberGenerator(SharedData sharedData) {
        this.sharedData = sharedData;
    }

    public void run() {
        Random random = new Random();
        while (true) {
            int number = random.nextInt(1000); // Change range to 0-999
            sharedData.setNumber(number);
            System.out.println("Generated number: " + number);
            try {
                Thread.sleep(1000); // Change sleep time to 1 second
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}

class SquareCalculator extends Thread {
    private SharedData sharedData;

    public SquareCalculator(SharedData sharedData) {
        this.sharedData = sharedData;
    }

    public void run() {
        while (true) {
            if (sharedData.getNumber() % 2 == 0) {
                int square = sharedData.getNumber() * sharedData.getNumber();
                System.out.println("Square of " + sharedData.getNumber() + ": " + square);
            }
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}

class CubeCalculator extends Thread {
    private SharedData sharedData;

    public CubeCalculator(SharedData sharedData) {
        this.sharedData = sharedData;
    }

    public void run() {
        while (true) {
            if (sharedData.getNumber() % 2 != 0) {
                int cube = sharedData.getNumber() * sharedData.getNumber() * sharedData.getNumber();
                System.out.println("Cube of " + sharedData.getNumber() + ": " + cube);
            }
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}

class SharedData {
    private int number;

    public synchronized int getNumber() {
        return number;
    }

    public synchronized void setNumber(int number) {
        this.number = number;
    }
}

public class Main {
    public static void main(String[] args) {
        SharedData sharedData = new SharedData();
        NumberGenerator numberGenerator = new NumberGenerator(sharedData);
        SquareCalculator squareCalculator = new SquareCalculator(sharedData);
        CubeCalculator cubeCalculator = new CubeCalculator(sharedData);

        numberGenerator.start();
        squareCalculator.start();
        cubeCalculator.start();
    }
}