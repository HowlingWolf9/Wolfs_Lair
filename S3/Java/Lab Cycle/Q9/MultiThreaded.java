import java.util.Random;

class RandomNumberGenerator implements Runnable {
    private Random random = new Random();

    public void run() {
        try {
            while (true) {
                int num = random.nextInt(100);
                System.out.println("Generated number:" + num);
                Thread squarethread = new Thread(new SquareCalculator(num));
                squarethread.start();
                Thread cubethread = new Thread(new CubeCalculator(num));
                cubethread.start();
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class SquareCalculator implements Runnable {
    private int number;

    public SquareCalculator(int number) {
        this.number = number;
    }

    public void run() {
        if (number % 2 == 0) {
            int square = number * number;
            System.out.println("SQUARE OF NUMBER " + number + ":" + square);
        }
    }
}

class CubeCalculator implements Runnable {
    private int number;

    public CubeCalculator(int number) {
        this.number = number;
    }

    public void run() {
        if (number % 2 != 0) {
            int cube = number * number * number;
            System.out.println("CUBE OF NUMBER " + number + ":" + cube);
        }
    }
}

class Multithreaded {
    public static void main(String args[]) {
        Thread numbergeneratorthread = new Thread(new RandomNumberGenerator());
        numbergeneratorthread.start();
    }
}
// bruh wtf is this
// No
